#include <string>
#include <stdexcept>

class MMKV {
public:
    static MMKV* mmkvWithID(const std::string& id, int size, int mode, std::string* cryptKey, std::string* path);
};

namespace mmkv {
    const int DEFAULT_MMAP_SIZE = 0;
}

const int MMKV_SINGLE_PROCESS = 0;
const int ANDROID_LOG_INFO = 4;

extern "C" int __android_log_print(int prio, const char* tag, const char* fmt, ...);

class MmkvHostObject {
public:
    MMKV* instance;
    MmkvHostObject(const std::string& instanceId, std::string path, std::string cryptKey);
};