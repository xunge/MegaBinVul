#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define ALOGV(...) printf(__VA_ARGS__)
#define ALOGE(...) printf(__VA_ARGS__)
#define ALOGW(...) printf(__VA_ARGS__)
#define android_errorWriteLog(...)

typedef int32_t status_t;
typedef int32_t sound_model_handle_t;
typedef int32_t audio_session_t;
typedef int32_t audio_io_handle_t;
typedef uint32_t audio_devices_t;

enum {
    NO_ERROR = 0,
    PERMISSION_DENIED = -1,
    BAD_VALUE = -2,
    INVALID_OPERATION = -3
};

enum sound_trigger_sound_model_type_t {
    SOUND_MODEL_TYPE_KEYPHRASE
};

struct sound_trigger_sound_model {
    sound_trigger_sound_model_type_t type;
    uint16_t version;
    uint16_t size;
    uint32_t data_offset;
    uint32_t data_size;
};

struct sound_trigger_phrase_sound_model {
    struct sound_trigger_sound_model header;
    uint32_t num_phrases;
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : mPtr(ptr) {}
    T* operator->() const { return mPtr; }
    T* get() const { return mPtr; }
    explicit operator bool() const { return mPtr != nullptr; }
    bool operator==(std::nullptr_t) const { return mPtr == nullptr; }
private:
    T* mPtr;
};

class IMemory {
public:
    virtual void* pointer() const = 0;
    virtual size_t size() const = 0;
    virtual ~IMemory() {}
};

class Model {
public:
    Model(sound_model_handle_t, audio_session_t, audio_io_handle_t, audio_devices_t, sound_trigger_sound_model_type_t) {}
};

class AutoMutex {
public:
    AutoMutex(void*) {}
};

template<typename K, typename V>
class KeyedVector {
public:
    size_t size() const { return 0; }
    void replaceValueFor(const K&, const V&) {}
};

class SoundTriggerHwService {
public:
    class Module {
    public:
        status_t loadSoundModel(const sp<IMemory>&, sound_model_handle_t*);
        static void soundModelCallback() {}
    private:
        void* mLock;
        KeyedVector<sound_model_handle_t, sp<Model>> mModels;
        struct {
            struct {
                int max_sound_models;
            } properties;
        } mDescriptor;
        struct {
            status_t (*load_sound_model)(void*, struct sound_trigger_sound_model*, void (*)(), void*, sound_model_handle_t*);
        }* mHwDevice;
    };
    static void soundModelCallback() {}
};

bool captureHotwordAllowed() { return true; }

class AudioSystem {
public:
    static status_t acquireSoundTriggerSession(audio_session_t*, audio_io_handle_t*, audio_devices_t*) { return NO_ERROR; }
};