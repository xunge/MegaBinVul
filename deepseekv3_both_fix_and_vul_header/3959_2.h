#include <string.h>

struct Header {
    const char* str_uninstchild;
    const char* str_uninstcmd;
    const char* str_wininit;
};

class CEXEBuild {
public:
    Header* cur_header;
    bool uninstall_mode;
    bool is_target_64bit();
    const char* add_asciistring(const char* str);
    void AddStandardStrings();
};