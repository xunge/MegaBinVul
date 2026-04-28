#include <string>
#include <cstdlib>

class stfl {
public:
    static void reset();
};

class utils {
public:
    static std::string replace_all(const std::string& str, const std::string& from, const std::string& to);
};

class config_container {
public:
    std::string get_configvalue(const std::string& key);
};

class pb_controller {
private:
    config_container* cfg;
public:
    void play_file(const std::string& file);
};

enum LogLevel {
    LOG_DEBUG
};

void LOG(LogLevel level, const char* fmt, ...);