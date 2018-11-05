#ifndef FLUSTER_COMPILER_DRIVER_H
#define FLUSTER_COMPILER_DRIVER_H

#include <string>
#include <map>
#include "parser.h"

/* Driver for connecting the lexer and parser
 * with a ~~shared~~ context
 */
struct Driver
{
    /// Members
    std::map<std::string, int> variables;
    bool trace_scanning;
    bool trace_parsing;
    yy::location location;
    std::string target_file;

    /// Construction
    Driver();

    /// Methods
    int parse(const std::string& in_file);
    void begin_scan();
    void end_scan();
}

#endif //FLUSTER_COMPILER_DRIVER_H
