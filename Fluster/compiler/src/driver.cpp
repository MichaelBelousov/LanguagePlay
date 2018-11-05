
#include "driver.h"

#include <string>
#include <map>

#include "parser.h"

/// Construction

Driver::Driver()
    : variables()
    , trace_scanning(false)
    , trace_parsing(false)
    , location()
    , target_file()
{}

/// Methods

int Driver::parse(const std::string& in_file)
{
    target_file = in_file;
    location.initialize(&file);
    scan_begin();
    yy::parser parse(*this);
    parse.set_debug_level(trace_parsing);
    int res = parse();
    scan_end();
    return res;
}

void Driver::begin_scan()
{
}

void Driver::end_scan()
{
}
