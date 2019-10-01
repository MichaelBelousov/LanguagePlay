#!/usr/bin/env python3

from importlib import reload
import grammar
from grammar import parse
import sys
import code

def repl_line():
    line = input('FORMAT> ')
    if line == 'RELOAD':
        reload(grammar)
        global parse
        parse = grammar.parse
    elif line == 'EXIT':
        sys.exit()
    elif line:
        result = parse(line)
        print(result)
        code.interact(local=locals())

if __name__ == '__main__':
    while True:
        try: 
            repl_line()
        except KeyboardInterrupt as exc:
            break
        except Exception as exc:
            print(exc)
