#include <iostream>
#include <string>

extern std::ostream DBG_FS;
extern std::ostream LOG_FS;
extern std::ostream ERR_FS;

bool looks_like_pbl(const std::string& filename);
bool ends_with(const std::string& str, const std::string& suffix);