'''
Sizr formatter proof of concept
'''

import pyparsing
from pyparsing import *
# pyparsing.ParserElement.inlineLiteralsUsing()
from functools import reduce
from operator import or_

import code  # XXX: for debug

class Break:
    def __init__(self, index, wrapped):
        self.index = index
        self.wrapped = wrapped

class NodeParseContext:
    def __init__(self, wraps):
        self.wraps: bool = wraps
        self.breaks: (list, Break) = []

class Node:
    def __init__(self, parsed):
        self.src = parsed

class ContextKey(Node):
    def __init__(self, parsed):
        self.key = parsed
        super().__init__(parsed)

p_ident = WordStart(alphas+'_') + Word(alphanums+'_')
p_ident.setName('identifier')

p_ref = (Suppress('$') + p_ident).setParseAction(ContextKey)
p_ref.setName('context reference')

p_quote = QuotedString('"', escChar='\\')
p_quote.setName('quote')

p_literal_text = ( Word(printables.replace("'",''))
                 | r"\'"  # TODO: put back the "'"
                 )
p_literal_text.setName('literal text')

p_atom = p_quote | p_literal_text
p_atom.setName('atom')

p_eq_expr = (
    reduce ( or_
           , map( lambda op: ( p_atom                   ('lhs')
                             + Suppress(Literal(op))    ('op')
                             + p_atom                   ('rhs')
                             )
                , ['<', '<=', '=', '!=', '>', '>=']
                )
           )
)
p_eq_expr.setName('binary expression')

p_expr = ( p_eq_expr
         | p_atom
         )
p_expr.setName('expression')

#TODO: temp definition
p_cond_expr = CharsNotIn('?')
p_cond_expr.setName('condition')

p_then_expr = p_expr.copy()
p_then_expr.setName('then body')

p_othw_expr = p_atom.copy()
p_othw_expr.setName('otherwise body')

p_then = Group(Suppress('?') + p_then_expr)
p_othw_expr.setName('then expression')

p_otherwise = Group(Suppress(':') + p_othw_expr)
p_othw_expr.setName('otherwise expression')

p_cond = Group( Suppress('#')
              + p_cond_expr             ('cond')
              + Optional(p_then)        ('then')
              + Optional(p_otherwise)   ('otherwise')
              )
p_cond.setName('conditional expression')

p_break = Group( Suppress('\\')
               + Optional(p_then)        ('then')
               + Optional(p_otherwise)   ('otherwise')
               )
p_break.setName('break expression')

class DynamicParserElement(ParserElement):
    def __init__(self, parse_elem):
        self.__parse_elem = parse_elem
    def __getattr__(self, name):
        if name in ('reset','_parse_elem'):
            return getattr(self, name)
        return getattr(self.__parse_elem, name)
    def reset(self, parse_elem):
        self.__parse_elem = parse_elem

# XXX: ew a global, it's just easier in this closed case for now
# will be replaced, maybe in the proper non-python backend
currentQuoteMatch = ''
def setCurrentQuoteMatch(x):
    global currentQuoteMatch
    currentQuoteMatch = x

class FollowedByWithFound(FollowedBy):
    """pyparsing.FollowedBy but returns what it found"""
    def parseImpl(self, in_string, loc, doActions=True):
        _, ret = self.expr._parse(in_string, loc, doActions=doActions)
        global currentQuoteMatch
        currentQuoteMatch = ret[0]
        del ret[:]
        return loc, ret

# need a better name than a "write"
p_write = ( p_ref
          | p_cond
          | p_break
          | p_expr
          )
p_write.setName('write action')

p_quote_delim = (
    Word("'")
    .setName('quote delimeter')
    .setParseAction(lambda t: setCurrentQuoteMatch(t[0]))
)

p_node_src = ZeroOrMore( p_write
                       , stopOn=p_quote_delim  #TODO: allow escaped
                       )
p_node_src.setName('node source')

p_node_decl = ( p_ident ('name')
              + Suppress(':')
              + Group(
                ( Suppress(p_quote_delim)
                + p_node_src
                + Suppress(
                    p_quote_delim
                    .copy()
                    # move condition to global or dynamic...?
                    .addCondition(lambda s,l,t: t[0] == currentQuoteMatch)
                  )
                ))      ('src')
              )
p_node_decl.setName('node declaration')

p_src = ZeroOrMore(p_node_decl)

def setDebug():
    for name, obj in globals().items():
        if isinstance(obj, ParserElement):
            obj.setDebug()

setDebug()

def parse(src):
    return p_src.parseString(src, parseAll=True)

