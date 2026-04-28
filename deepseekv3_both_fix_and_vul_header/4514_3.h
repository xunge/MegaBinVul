#include <cstddef>
#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;
#define BAD_VALUE (-1)
#define INVALID_OPERATION (-2)
#define OK (0)

#define CAMERA3_TEMPLATE_COUNT 6

typedef struct camera_metadata camera_metadata_t;

class CameraMetadata {
public:
    CameraMetadata() {}
    CameraMetadata(const camera_metadata_t*) {}
    bool isEmpty() const { return false; }
    CameraMetadata& operator=(const camera_metadata_t*) { return *this; }
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class IPCThreadState {
public:
    static IPCThreadState* self();
    int getCallingUid();
};

class CameraService {
public:
    static constexpr int SN_EVENT_LOG_ID = 0;
};

void android_errorWriteWithInfoLog(int, const char*, int, const char*, int);

class ATRACE_CALL {};
class ATRACE_BEGIN {
public:
    ATRACE_BEGIN(const char*) {}
};
class ATRACE_END {};

#define ALOGV(...)
#define ALOGI(...)
#define CLOGE(...)
#define SET_ERR_L(...)

struct camera3_device_ops {
    camera_metadata_t* (*construct_default_request_settings)(struct camera3_device*, int);
};

struct camera3_device {
    camera3_device_ops* ops;
};

enum DeviceStatus {
    STATUS_ERROR,
    STATUS_UNINITIALIZED,
    STATUS_UNCONFIGURED,
    STATUS_CONFIGURED,
    STATUS_ACTIVE
};

class Camera3Device {
private:
    Mutex mInterfaceLock;
    Mutex mLock;
    DeviceStatus mStatus;
    CameraMetadata mRequestTemplateCache[CAMERA3_TEMPLATE_COUNT];
    camera3_device* mHal3Device;
public:
    status_t createDefaultRequest(int templateId, CameraMetadata* request);
};