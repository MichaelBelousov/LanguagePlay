
"""
test literal loading.

The lexer provides strong guarantees that the passed tokens are in
the correct form, so handling invalid forms is unnecessary.
"""
# XXX: I'm experimenting with unit testing C++ in python...

import unittest
import cppyy
from textwrap import dedent

# define a TestCase subclass for cpp tests?
class TestReadHex(unittest.TestCase):
    def __init__(self):
        try:
            cppyy.load_reflection_info('lib/lexer_routines.so')  # FIXME: load from *.cpp
            cppyy.include('src/lexer_routines.h')
            #cppyy.cppdefs(open(target))
            from cppyy.gbl import lexer_routines
        except OSError as err:  # no such directory
            print(dedent('''
                         Test not being run in 
                         the root directory
                         '''))
            raise

    def test_allset(self):
        self.assertEqual(lexer_routines.make_HEXBYTES('0xfffffffff'),
                         b'\x0f\xff\xff\xff\xff')

    def test_allchars(self):
        self.assertEqual(
                lexer_routines.make_HEXBYTES('0x1a2b3c4d5e6f7a8b9c0d'),
                b'\x1a\x2b\x3c\x4d\x5e\x6f\x7a\x8b\x9c\x0d')

    def test_first100(self):
        for i in range(256):
            self.assertEqual(
                    lexer_routines.make_HEXBYTES(hex(i)),
                    i.to_bytes(1, 'little'))  #TODO: settle endianness?
                    # sys.byteorder or something?

    
if __name__ == '__main__':
    load()
    unittest.main()

