#!/usr/bin/env python3

from importlib import reload
import grammar
from grammar import parse
import sys
import code
import argparse
import python_backend

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

def repl():
    import traceback
    while True:
        try: 
            repl_line()
        except KeyboardInterrupt:
            break
        except EOFError:
            break
        except Exception as exc:
            traceback.print_exc()
            print(exc)

if __name__ == '__main__':
    argparser = argparse.ArgumentParser(description='format a file')
    argparser.add_argument('destination_paths', nargs='*',
                           help='paths to destination source files')
    argparser.add_argument('--interactive', '-i', action='store_true',
                           help='run the repl instead of on a file')
    argparser.add_argument('--format-defs', '-d', 
                           help='the formatting definitions file to use')
    args = argparser.parse_args()

    if args.interactive:
        repl()

    with open(args.format_defs) as format_src_file:
        format_src = format_src_file.read()
        formats = parse(format_src)
        for path in args.destination_paths:
            with open(path) as file:
                python_backend.format_src(formats,
                                          file.read())


