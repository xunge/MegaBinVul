#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

typedef int status_t;
#define OK 0
#define UNKNOWN_ERROR (-1)

template<typename T>
class sp {
    T* m_ptr;
public:
    sp() : m_ptr(nullptr) {}
    sp(T* ptr) : m_ptr(ptr) {}
    T* operator->() { return m_ptr; }
    const T* operator->() const { return m_ptr; }
    void clear() { m_ptr = nullptr; }
    bool operator!=(const void* ptr) { return m_ptr != ptr; }
    bool operator==(const void* ptr) { return m_ptr == ptr; }
    operator T*() { return m_ptr; }
    template<typename U> sp(const sp<U>& other) : m_ptr(other.operator->()) {}
    template<typename U> sp<T>& operator=(const sp<U>& other) { 
        m_ptr = const_cast<sp<U>&>(other).operator->(); 
        return *this; 
    }
};

class String8 {
    char* m_str;
public:
    const char* string() { return m_str; }
    bool isEmpty() { return !m_str || !*m_str; }
};

class AMessage {};
class DataSource {
public:
    bool sniff(String8*, float*, sp<AMessage>*);
};
class MetaData {
public:
    bool findInt64(int, int64_t*);
    bool findCString(int, const char**);
    bool findInt32(int, int32_t*);
};
class MediaSource {
public:
    MetaData* getFormat();
};
class MediaExtractor {
public:
    static MediaExtractor* Create(DataSource*, const char*);
    bool getDrmFlag();
    MetaData* getMetaData();
    size_t countTracks();
    MediaSource* getTrack(size_t);
    MetaData* getTrackMetaData(size_t);
    void setUID(unsigned int);
};
class WVMExtractor : public MediaExtractor {
public:
    WVMExtractor(DataSource*);
    void setAdaptiveStreamingMode(bool);
    void setUID(unsigned int);
};
class AnotherPacketSource {
public:
    AnotherPacketSource(MetaData*);
};

#define CHECK(expr) ((void)0)
#define ALOGE(...) ((void)0)
#define MEDIA_MIMETYPE_CONTAINER_WVM "video/wvm"
#define MEDIA_MIMETYPE_AUDIO_VORBIS "audio/vorbis"
#define kKeyDuration 0
#define kKeyMIMEType 0
#define kKeyRequiresSecureBuffers 0
#define kKeyBitRate 0

struct NuPlayer {
    struct GenericSource {
        sp<DataSource> mDataSource;
        sp<DataSource> mHttpSource;
        sp<WVMExtractor> mWVMExtractor;
        sp<MetaData> mFileMeta;
        bool mIsWidevine;
        bool mIsStreaming;
        bool mUIDValid;
        unsigned int mUID;
        bool mIsSecure;
        int64_t mDurationUs;
        int32_t mBitrate;
        bool mAudioIsVorbis;
        sp<DataSource> mCachedSource;

        struct Track {
            size_t mIndex;
            sp<MediaSource> mSource;
            sp<AnotherPacketSource> mPackets;
        };

        Track mAudioTrack;
        Track mVideoTrack;

        template<typename T>
        struct Vector {
            void push(T) {}
            size_t size() { return 0; }
        };

        Vector<sp<MediaSource>> mSources;

        status_t initFromDataSource();
        void checkDrmStatus(const sp<DataSource>& dataSource);
    };
};

bool SniffWVM(const sp<DataSource>& dataSource, String8* mimeType, float* confidence, sp<AMessage>* dummy);