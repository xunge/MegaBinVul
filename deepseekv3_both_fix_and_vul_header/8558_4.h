#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef int32_t sound_model_handle_t;
typedef int32_t status_t;

struct sound_trigger_recognition_config {
    size_t data_offset;
    size_t data_size;
    uint32_t capture_handle;
    uint32_t capture_device;
};

template<typename T> class sp {
    T* m_ptr;
public:
    sp() : m_ptr(0) {}
    sp(T* other) : m_ptr(other) {}
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
};

class IMemory {
public:
    virtual void* pointer() const = 0;
    virtual size_t size() const = 0;
};

class AutoMutex {
public:
    AutoMutex(void*) {}
};

class Model {
public:
    enum State {
        STATE_INACTIVE,
        STATE_ACTIVE
    };
    State mState;
    uint32_t mCaptureIOHandle;
    uint32_t mCaptureDevice;
    sound_trigger_recognition_config mConfig;
};

struct hw_device_t {
    int (*start_recognition)(hw_device_t*, sound_model_handle_t, 
                           sound_trigger_recognition_config*,
                           void (*callback)(),
                           void*);
};

enum sound_trigger_state {
    SOUND_TRIGGER_STATE_DISABLED,
    SOUND_TRIGGER_STATE_ENABLED
};

class SoundTriggerHwService {
public:
    static void recognitionCallback();
    
    class Module {
    public:
        status_t startRecognition(sound_model_handle_t handle, const sp<IMemory>& dataMemory);
    private:
        void* mLock;
        sound_trigger_state mServiceState;
        sp<Model> getModel(sound_model_handle_t handle);
        hw_device_t* mHwDevice;
        bool captureHotwordAllowed();
    };
};

enum {
    PERMISSION_DENIED = -1,
    BAD_VALUE = -2,
    INVALID_OPERATION = -3,
    NO_ERROR = 0
};

#define ALOGV(...)
#define ALOGE(...)