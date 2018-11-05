
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

class TestReadHex(unittest.TestCase):
    def __init__(self):
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

    def test_badcontent(self):
        """test"""
        lexer_routines.make_HEXBYTES("0x!2")

    def test_badprefix(self):
        lexer_routines.make_HEXBYTES("0x!2")

    def test_first100(self):
        for i in range(100):
            self.assertEqual(
                    lexer_routines.make_HEXBYTES(hex(i)),
                    i.to_bytes())


    
if __name__ == '__main__':
    load()
    unittest.main()

