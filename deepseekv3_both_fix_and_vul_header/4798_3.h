#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef int32_t status_t;
typedef uint32_t audio_source_t;
#define OK 0
#define ALOGV(...)
#define CHECK(condition)

class String16 {
public:
    String16(const String16&);
    String16();
    ~String16();
};

class AudioRecord {
public:
    typedef void (*callback_t)(int, void*, void*);
    AudioRecord(audio_source_t, uint32_t, int, int, const String16&, size_t, callback_t, void*, size_t);
    status_t initCheck();
    static status_t getMinFrameCount(size_t*, uint32_t, int, int);
};

template<typename T>
class sp {
public:
    sp() : ptr(nullptr) {}
    sp(T* p) : ptr(p) {}
    T* operator->() { return ptr; }
    void clear() { ptr = nullptr; }
    T* get() { return ptr; }
private:
    T* ptr;
};

class AudioSource {
public:
    AudioSource(audio_source_t, const String16&, uint32_t, uint32_t, uint32_t);
private:
    bool mStarted;
    uint32_t mSampleRate;
    uint32_t mOutSampleRate;
    bool mTrackMaxAmplitude;
    int64_t mStartTimeUs;
    int16_t mMaxAmplitude;
    int64_t mPrevSampleTimeUs;
    int64_t mFirstSampleTimeUs;
    int64_t mInitialReadTimeUs;
    uint32_t mNumFramesReceived;
    uint32_t mNumClientOwnedBuffers;
    sp<AudioRecord> mRecord;
    status_t mInitCheck;
};

#define AUDIO_FORMAT_PCM_16_BIT 0
#define kMaxBufferSize 4096

int audio_channel_in_mask_from_count(uint32_t);
void AudioRecordCallbackFunction(int event, void* user, void* info);