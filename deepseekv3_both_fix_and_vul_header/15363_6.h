#include <vector>
#include <stdint.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <memory>

#define AUDIO_ATTRIBUTES_TAGS_MAX_SIZE 256
#define AUDIO_CHANNEL_NONE 0
#define AUDIO_FORMAT_DEFAULT 1
#define AUDIO_STREAM_DEFAULT 0

typedef int32_t status_t;
typedef int32_t audio_port_handle_t;
typedef int32_t audio_io_handle_t;
typedef uint32_t audio_channel_mask_t;
typedef uint32_t audio_stream_type_t;
typedef uint32_t audio_output_flags_t;
typedef uint32_t audio_input_flags_t;
typedef uint32_t audio_format_t;

struct audio_attributes_t {
    int32_t contentType;
    int32_t usage;
    int32_t source;
    int32_t flags;
    char tags[AUDIO_ATTRIBUTES_TAGS_MAX_SIZE];
};

struct audio_config_t {
    uint32_t sample_rate;
    audio_channel_mask_t channel_mask;
    audio_format_t format;
    audio_attributes_t offload_info;
};

struct audio_config_base_t {
    uint32_t sample_rate;
    audio_channel_mask_t channel_mask;
    audio_format_t format;
};

struct AttributionSourceState {
    int32_t uid;
    int32_t pid;
    const char* packageName;
};

struct AudioClient {
    AttributionSourceState attributionSource;
};

#define NO_ERROR 0
#define NO_INIT (-ENODEV)
#define BAD_VALUE (-EINVAL)
#define PERMISSION_DENIED (-EPERM)
#define AUDIO_PORT_HANDLE_NONE 0
#define AUDIO_CONFIG_INITIALIZER {0, AUDIO_CHANNEL_NONE, AUDIO_FORMAT_DEFAULT, {0}}
#define AUDIO_OUTPUT_FLAG_MMAP_NOIRQ (0x800)
#define AUDIO_OUTPUT_FLAG_DIRECT (0x4)
#define AUDIO_INPUT_FLAG_MMAP_NOIRQ (0x800)
#define RECORD_RIID_INVALID (-1)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
    void lock() {}
    void unlock() {}
};

template<typename T>
class Vector {
public:
    bool isEmpty() const { return true; }
    void add(const T& item) {}
    typedef T* iterator;
    typedef const T* const_iterator;
    iterator begin() { return nullptr; }
    iterator end() { return nullptr; }
    const_iterator begin() const { return nullptr; }
    const_iterator end() const { return nullptr; }
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : mPtr(ptr) {}
    T* get() { return mPtr; }
    T* operator->() { return mPtr; }
    const T* operator->() const { return mPtr; }
    bool operator!=(int value) const { return mPtr != nullptr; }
private:
    T* mPtr;
};

class HalStream {
public:
    void stop() {}
};

class MmapTrack {
public:
    MmapTrack(void* thread, const audio_attributes_t& attr, uint32_t sampleRate,
             audio_format_t format, audio_channel_mask_t channelMask,
             uint32_t sessionId, bool isOutput,
             const AttributionSourceState& attributionSource,
             int32_t pid, audio_port_handle_t portId) {}
    void setSilenced_l(bool silenced) {}
    bool isSilenced_l() const { return false; }
    int32_t uid() const { return 0; }
    void invalidate() const {}
    void logBeginInterval(const char* str) {}
};

class EffectChain {
public:
    void setStrategy(uint32_t strategy) {}
    void incTrackCnt() {}
    void incActiveTrackCnt() {}
};

class IPCThreadState {
public:
    static IPCThreadState* self();
    int32_t getCallingPid();
};

class AudioSystem {
public:
    static status_t getOutputForAttr(const audio_attributes_t* attr, audio_io_handle_t* output,
                                    uint32_t sessionId, audio_stream_type_t* stream,
                                    const AttributionSourceState& attributionSource,
                                    const audio_config_t* config, audio_output_flags_t flags,
                                    audio_port_handle_t* selectedDeviceId, audio_port_handle_t* portId,
                                    std::vector<audio_io_handle_t>* secondaryOutputs, bool* isSpatialized);
    
    static status_t getInputForAttr(const audio_attributes_t* attr, audio_io_handle_t* input,
                                   uint32_t riid, uint32_t sessionId,
                                   const AttributionSourceState& attributionSource,
                                   const audio_config_base_t* config, audio_input_flags_t flags,
                                   audio_port_handle_t* selectedDeviceId, audio_port_handle_t* portId);
    
    static status_t startOutput(audio_port_handle_t portId);
    static status_t startInput(audio_port_handle_t portId);
    static status_t releaseOutput(audio_port_handle_t portId);
    static status_t releaseInput(audio_port_handle_t portId);
};

class AudioFlinger {
public:
    static AttributionSourceState checkAttributionSourcePackage(const AttributionSourceState& state);
    
    class MmapThread {
    public:
        uint32_t mSampleRate;
        audio_channel_mask_t mChannelMask;
        audio_format_t mFormat;
        audio_io_handle_t mId;
        audio_port_handle_t mPortId;
        audio_port_handle_t mDeviceId;
        uint32_t mSessionId;
        audio_attributes_t mAttr;
        bool mStandby;
        HalStream* mHalStream;
        float mHalVolFloat;
        Mutex mLock;
        Vector<sp<MmapTrack>> mActiveTracks;
        void* mPatch;
        
        bool isOutput() const { return true; }
        audio_stream_type_t streamType() const { return AUDIO_STREAM_DEFAULT; }
        status_t exitStandby() { return NO_ERROR; }
        void acquireWakeLock() {}
        void setClientSilencedState_l(audio_port_handle_t portId, bool silenced) {}
        bool isClientSilenced_l(audio_port_handle_t portId) { return false; }
        void eraseClientSilencedState_l(audio_port_handle_t portId) {}
        void broadcast_l() {}
        sp<EffectChain> getEffectChain_l(uint32_t sessionId) { return nullptr; }
        uint32_t getStrategyForStream(audio_stream_type_t stream) { return 0; }
        const char* patchSinksToString(void* patch) { return ""; }
        
        status_t start(const AudioClient& client, const audio_attributes_t* attr, audio_port_handle_t* handle);
    };
};

#define ALOGV(...) 
#define ALOGD_IF(...) 
#define ALOGE(...) 
#define __FUNCTION__ ""