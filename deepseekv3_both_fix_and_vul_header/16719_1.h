#include <string>
#include <dlfcn.h>

class IsolateEnvironment {
public:
    static IsolateEnvironment* GetCurrent();
    bool IsDefault();
};

class RuntimeGenericError {
public:
    RuntimeGenericError(const std::string& message);
};

struct uv_lib_t {
    void* handle;
};

extern "C" {
    int uv_dlopen(const char* filename, uv_lib_t* lib);
    int uv_dlsym(uv_lib_t* lib, const char* name, void** ptr);
    int uv_dlclose(uv_lib_t* lib);
}

class NativeModule {
private:
    void* init;
    uv_lib_t lib;
public:
    NativeModule(const std::string& filename);
};