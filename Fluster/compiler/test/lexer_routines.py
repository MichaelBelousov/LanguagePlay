
"""
test lexer routines

"""
# XXX: I'm experimenting with unit testing C++ in python...

import unittest
import cppyy
from textwrap import dedent

# TODO: maybe define a superclass so all tests have the same interface?
def load():
    """load the code to be tested"""
    try:
        cppyy.load_reflection_info('lib/lexer_routines.so')  # FIXME: load from *.cpp
        cppyy.include('src/lexer_routines.h')
        from cppyy.gbl import lexer_routines
    except OSError as err:  # no such directory
        print(dedent('''
                     Test not being run in 
                     the root directory
                     '''))
        raise

    
if __name__ == '__main__':
    load()

