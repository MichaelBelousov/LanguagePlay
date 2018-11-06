/*
 * C++ test cases for literal loading
 */

#include <iostream>


//returns a flag word where each set bit is a failed test
int runTests {
    int failure_word;
    auto record_result = [&failure_word](bool result) -> void
        { failure_word = (failure_word << 1) | static_cast<int>(result) };
}

int main(int argc, char* argv[])
{
    return runTests();
}
