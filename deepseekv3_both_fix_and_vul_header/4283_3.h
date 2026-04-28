#include <sys/types.h>
#include <unistd.h>
#include <string>

#define AID_SHELL 2000

class String8 {
public:
    void appendFormat(const char* fmt, ...);
};

class String16 {
public:
    String16(const char* str);
};

class IPCThreadState {
public:
    static IPCThreadState* self();
    pid_t getCallingPid() const;
    uid_t getCallingUid() const;
};

class PermissionCache {
public:
    static bool checkPermission(String16 permission, pid_t pid, uid_t uid);
};

struct Core {
    void dump(String8& result, const char* prefix);
};

class BufferQueueConsumer {
private:
    Core* mCore;
public:
    void dump(String8& result, const char* prefix) const;
};