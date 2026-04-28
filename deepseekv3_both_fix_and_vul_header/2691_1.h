#include <string>
#include <iostream>
#include <cassert>

namespace game_config {
    extern std::string path;
}

#define DBG_FS std::cerr
#define LOG_FS std::cerr
#define ERR_FS std::cerr

bool ends_with(const std::string& str, const std::string& suffix);
std::string get_user_data_dir();
bool file_exists(const std::string& path);
bool is_directory(const std::string& path);