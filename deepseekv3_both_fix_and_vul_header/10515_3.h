#include <stdint.h>
#include <sys/types.h>
#include <cstddef>

typedef int32_t status_t;
typedef int64_t off64_t;

#define OK 0
#define ERROR_END_OF_STREAM (-1)
#define ERROR_MALFORMED (-2)
#define ERROR_IO (-3)
#define ALOGE(...)

enum {
    kKeyTime = 0,
    kKeyIsSyncFrame = 1
};

class MediaBuffer {
public:
    void* data();
    void release();
    void set_range(size_t offset, size_t size);
    class MetaData {
    public:
        void setInt64(int key, int64_t value);
        void setInt32(int key, int32_t value);
    };
    MetaData* meta_data();
};

class DataSource {
public:
    ssize_t readAt(off64_t offset, void* data, size_t size);
};

class MediaBufferGroup {
public:
    status_t acquire_buffer(MediaBuffer** buffer);
};

struct ReadOptions {
    enum SeekMode {
        SEEK_PREVIOUS_SYNC,
        SEEK_NEXT_SYNC,
        SEEK_CLOSEST_SYNC,
        SEEK_CLOSEST
    };
    bool getSeekTo(int64_t* time_us, SeekMode* mode) const;
};

class AMRSource {
public:
    status_t read(MediaBuffer** out, const ReadOptions* options);
private:
    DataSource* mDataSource;
    MediaBufferGroup* mGroup;
    bool mIsWide;
    off64_t mOffset;
    int64_t mCurrentTimeUs;
    off64_t* mOffsetTable;
    size_t mOffsetTableLength;

    static status_t getFrameSizeByOffset(DataSource* source, off64_t offset, bool isWide, size_t* size);
    static size_t getFrameSize(bool isWide, unsigned FT);
};