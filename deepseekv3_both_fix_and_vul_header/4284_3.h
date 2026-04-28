#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

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
    static bool checkPermission(const String16& permission, pid_t pid, uid_t uid);
};

void android_errorWriteWithInfoLog(uint32_t tag, const char* subTag, uid_t uid, const char* data, uint32_t dataLen);

class BufferQueueConsumer {
public:
    void dump(String8& result, const char* prefix) const;
private:
    struct Core {
        void dump(String8& result, const char* prefix) const;
    };
    Core* mCore;
};