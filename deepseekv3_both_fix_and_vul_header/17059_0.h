#include <string>
#include <vector>
#include <stdexcept>

#define RESET_ERROR
#define kXMPFiles_IgnoreLocalText 0

class XMP_Error : public std::runtime_error {
public:
    XMP_Error(const std::string& msg) : std::runtime_error(msg) {}
};

class SXMPFiles {
public:
    static bool Initialize(int flags);
};

class SXMPMeta {
public:
    static void SetDefaultErrorCallback(void (*callback)(void*, void*, void*), void* context, int flags);
};

void _xmp_error_callback(void*, void*, void*);
void set_error(const XMP_Error& e);