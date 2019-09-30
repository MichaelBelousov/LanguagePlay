#!/usr/bin/env python3
'''
Sizr formatter proof of concept
'''

import pyparsing
from pyparsing import *
pyparsing.ParserElement.inlineLiteralsUsing(Suppress)

p_ident = WordStart(alphas+'_') + Word(alphanums+'_')
p_int = Word(nums)

p_ref = Group('$' + p_ident)

p_quote = QuotedString('"', escChar='\\')

#TODO: temp definition
p_cond_expr = CharsNotIn('?')
p_then_expr = CharsNotIn(':')
p_othw_expr = Word(printables)

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

p_literal = Word(printables)

# need a better name than a "write"
p_writes = ( p_ref
           | p_cond
           | p_break
           | p_quote
           | p_literal
           )

p_src = ZeroOrMore(p_writes)

#p_else  #all other possible write expressions

p_node_decl = ( p_ident
              + ':'
              + Word("'")
              + Word("'")
              )

def parse(src):
    return p_src.parseString(src, parseAll=True)

