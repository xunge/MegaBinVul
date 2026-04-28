#include <stdint.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using std::max;

typedef int32_t status_t;
#define NO_ERROR 0
#define BAD_VALUE -1
#define PERMISSION_DENIED -2
#define BAD_TYPE -3

typedef uint32_t audio_channel_mask_t;
typedef uint32_t audio_format_t;
typedef uint32_t audio_input_flags_t;
typedef uint32_t audio_session_t;
typedef uint32_t audio_port_handle_t;

#define AUDIO_INPUT_FLAG_FAST 0x1
#define AUDIO_INPUT_FLAG_DIRECT 0x2
#define AUDIO_INPUT_FLAG_RAW 0x4

struct audio_attributes_t {
    int dummy;
};

class String16 {
public:
    String16() {}
    String16(const char*) {}
    bool empty() const { return false; }
    bool operator==(const String16&) const { return false; }
};

template<typename T>
class sp {
public:
    sp() {}
    sp(T*) {}
    T* operator->() { return nullptr; }
    bool operator!=(int) const { return false; }
    T* get() { return nullptr; }
    operator T*() { return nullptr; }
};

template<typename T>
class Vector {
public:
    void add(const T&) {}
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

struct AttributionSourceState {
    String16 packageName;
};

class AudioInput {
public:
    audio_input_flags_t flags;
};

class EffectChain {
public:
    void checkInputFlagCompatibility(audio_input_flags_t*) {}
};

class TrackBase {
public:
    enum Type { TYPE_DEFAULT };
};

class IPCThreadState {
public:
    static IPCThreadState* self() { return nullptr; }
    pid_t getCallingPid() { return 0; }
};

class AudioFlinger {
public:
    class Client {};
    class RecordThread {
    public:
        class RecordTrack : public TrackBase {
        public:
            RecordTrack(RecordThread*, const sp<Client>&, const audio_attributes_t&, 
                       uint32_t, audio_format_t, audio_channel_mask_t, size_t, 
                       void*, size_t, audio_session_t, pid_t, 
                       const AttributionSourceState&, audio_input_flags_t, 
                       Type, audio_port_handle_t, int32_t) {}
            status_t initCheck() { return NO_ERROR; }
        };
        
        AudioInput* mInput;
        Mutex mLock;
        uint32_t mSampleRate;
        audio_format_t mFormat;
        audio_channel_mask_t mChannelMask;
        size_t mPipeFramesP2;
        size_t mFrameCount;
        int32_t mMaxSharedAudioHistoryMs;
        bool mFastTrackAvail;
        String16 mSharedAudioPackageName;
        audio_session_t mSharedAudioSessionId;
        int32_t mSharedAudioStartFrames;
        Vector<sp<RecordTrack>> mTracks;

        status_t initCheck() { return NO_ERROR; }
        bool hasFastCapture() { return false; }
        bool captureHotwordAllowed(const AttributionSourceState&) { return false; }
        sp<EffectChain> getEffectChain_l(audio_session_t) { return nullptr; }
        void sendPrioConfigEvent_l(pid_t, pid_t, int, bool) {}
        void sendResizeBufferConfigEvent_l(int32_t) {}

        sp<RecordTrack> createRecordTrack_l(
            const sp<Client>&,
            const audio_attributes_t&,
            uint32_t*,
            audio_format_t,
            audio_channel_mask_t,
            size_t*,
            audio_session_t,
            size_t*,
            pid_t,
            const AttributionSourceState&,
            audio_input_flags_t*,
            pid_t,
            status_t*,
            audio_port_handle_t,
            int32_t);
    };
    static constexpr int32_t kMaxSharedAudioHistoryMs = 10000;
    static AttributionSourceState checkAttributionSourcePackage(const AttributionSourceState&) { return AttributionSourceState(); }
};

inline bool audio_is_linear_pcm(audio_format_t) { return true; }

enum {
    kPriorityAudioApp = 2
};

#define ALOGE(...)
#define ALOGW(...) 
#define ALOGV(...)
#define ALOGV_IF(...)