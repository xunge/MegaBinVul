#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>

struct RESULT;
struct DATA {
    char* receptor;
    char* ligand;
    double seed;
    float score;
};
struct OUTPUT_FILE_INFO {
    std::string path;
};
extern int errno;

class LogMessages {
public:
    void printf(int level, const char* format, ...);
};
extern LogMessages log_messages;

const int MSG_DEBUG = 0;
const int MSG_CRITICAL = 1;

int get_output_file_path(RESULT& result, std::string& path);