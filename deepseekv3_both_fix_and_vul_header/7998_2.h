#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int status_t;
#define OK 0

template<typename T> class sp {
public:
    sp(T* ptr) : mPtr(ptr) {}
    operator T*() { return mPtr; }
    T* mPtr;
};

class MediaSource {};

class MetaData {
public:
    bool findInt32(int32_t key, int32_t* value);
};

class MPEG4Extractor {
public:
    struct Track {
        MetaData* meta;
        Track* next;
        uint32_t timescale;
        void* sampleTable;
    };

    struct Trex {
        uint32_t track_ID;
    };

    sp<MediaSource> getTrack(size_t index);
    status_t readMetaData();
    size_t mPssh;
    Track* mFirstTrack;
    void* mDataSource;
    void* mSidxEntries;
    int64_t mMoofOffset;

    template<typename T> class Vector {
    public:
        size_t size();
        T& editItemAt(size_t index);
    };
    Vector<Trex> mTrex;
};

class MPEG4Source : public MediaSource {
public:
    MPEG4Source(MPEG4Extractor* extractor, MetaData* meta, void* dataSource,
                uint32_t timescale, void* sampleTable, void* sidxEntries,
                MPEG4Extractor::Trex* trex, int64_t moofOffset);
};

#define ALOGE(...)
#define ALOGV(...)
#define kKeyTrackID 0