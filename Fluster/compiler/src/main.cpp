
#include "lexer.h"
#include "parser.tab.h"

int main(int argc, char*[] argv)
{
    using Parser = yy::parser;
    using yy::Lexer;

    Lexer lexer(std::cin);
    Parser parser(lexer);

    if (parser.parse() != 0)
        return -1;
    else
        return 0;
}
