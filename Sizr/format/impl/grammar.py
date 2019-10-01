'''
Sizr formatter proof of concept
'''

import pyparsing
from pyparsing import *
pyparsing.ParserElement.inlineLiteralsUsing(Suppress)
from functools import reduce
from operator import or_

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

p_ref = ('$' + p_ident).setParseAction(ContextKey)

p_quote = QuotedString('"', escChar='\\')

p_atom = p_quote | Word(printables)

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

p_expr = ( p_eq_expr
         | p_atom
         )

#TODO: temp definition
p_cond_expr = CharsNotIn('?')
p_then_expr = p_expr
p_othw_expr = p_atom

p_then = Group('?' + p_then_expr)
p_otherwise = Group(':' + p_othw_expr)

p_cond = Group( '#'
              + p_cond_expr             ('cond')
              + Optional(p_then)        ('then')
              + Optional(p_otherwise)   ('otherwise')
              )

p_break = Group( '\\'
               + Optional(p_then)        ('then')
               + Optional(p_otherwise)   ('otherwise')
               )

# rename to p_else or p_any...?
p_literal = Word(printables)

# need a better name than a "write"
p_writes = ( p_ref
           | p_cond
           | p_break
           | p_quote  #p_expr
           | p_literal
           )

p_src = ZeroOrMore(p_writes)

p_node_decl = ( p_ident
              + ':'
              + Word("'")
              + Word("'")
              )

def parse(src):
    return p_src.parseString(src, parseAll=True)

