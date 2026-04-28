#include <cstdio>
#include <cassert>
#include <string>

enum OpMode { opRead, opWrite, opSeek };
enum WpMode { wpUnicode };

struct FileIo {
    struct Impl {
        FILE* fp_;
        OpMode opMode_;
        std::string openMode_;
        std::string path_;
#ifdef EXV_UNICODE_PATH
        WpMode wpMode_;
        std::wstring wpath_;
#endif
        int switchMode(OpMode opMode);
    };
};