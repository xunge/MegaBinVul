#include <string>
#include <iostream>

#define DBG_FS std::cout
#define LOG_FS std::cout
#define ERR_FS std::cerr

static bool ends_with(const std::string &str, const std::string &suffix) {
    return str.size() >= suffix.size() && 
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}