#include <string>
#include <cassert>
#include <iostream>

namespace game_config {
    extern std::string path;
}

extern std::ostream DBG_FS;
extern std::ostream LOG_FS;
extern std::ostream ERR_FS;

bool looks_like_pbl(const std::string& filename);
bool ends_with(const std::string& str, const std::string& suffix);
std::string get_user_data_dir();
bool file_exists(const std::string& path);
bool is_directory(const std::string& path);