#!/usr/bin/env python3
'''
Sizr formatter proof of concept
'''

from pyparsing import *

p_ident = WordStart(alphas+'_') + Word(alphanums+'_')
p_int = Word(nums)

p_ref = '$' + p_ident

p_then = '?' + p_expr           ('expr')
p_otherwise = ':' + p_expr      ('expr')
p_cond_expr = ( '#'
              + p_expr                  ('cond')
              + Optional(p_then)        ('then')
              + Optional(p_otherwise)   ('otherwise')
              )

p_break = ( '\\'
          + Optional(p_then)        ('then')
          + Optional(p_otherwise)   ('otherwise')
          )

# need a better name than a "write"
p_writes = ( p_ref
           | p_cond_expr
           | p_break_expr
           )

p_quote = QuotedString('"', escChar='\\')

p_src = ZeroOrMore(p_writes)

#p_else  #all other possible write expressions

p_node_decl = p_ident + ':' + Word("'") + Word("'")
