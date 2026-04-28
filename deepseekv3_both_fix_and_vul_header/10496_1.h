#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef int64_t off64_t;

template<typename T>
class sp {
public:
    sp(T* ptr) {}
    sp(const sp<T>& other) {}
    T* operator->() const { return nullptr; }
};

class DataSource {};
class MetaData {};

enum FLAC__StreamDecoderErrorStatus {
    FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC = 0,
    FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER,
    FLAC__STREAM_DECODER_ERROR_STATUS_FRAME_CRC_MISMATCH,
    FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM
};

struct FLAC__StreamMetadata_StreamInfo {
    uint32_t min_blocksize;
    uint32_t max_blocksize;
    uint32_t min_framesize;
    uint32_t max_framesize;
    uint32_t sample_rate;
    uint32_t channels;
    uint32_t bits_per_sample;
    uint64_t total_samples;
    uint8_t md5sum[16];
};

struct FLAC__FrameHeader {
    uint32_t blocksize;
    uint32_t sample_rate;
    uint32_t channels;
    uint32_t channel_assignment;
    uint32_t bits_per_sample;
    uint8_t number_type;
};

class FLACParser {
public:
    FLACParser(const sp<DataSource>& dataSource,
               const sp<MetaData>& fileMetadata,
               const sp<MetaData>& trackMetadata);
private:
    sp<DataSource> mDataSource;
    sp<MetaData> mFileMetadata;
    sp<MetaData> mTrackMetadata;
    bool mInitCheck;
    size_t mMaxBufferSize;
    void* mGroup;
    void (*mCopy)(void);
    void* mDecoder;
    off64_t mCurrentPos;
    bool mEOF;
    bool mStreamInfoValid;
    bool mWriteRequested;
    bool mWriteCompleted;
    void* mWriteBuffer;
    FLAC__StreamDecoderErrorStatus mErrorStatus;
    FLAC__StreamMetadata_StreamInfo mStreamInfo;
    FLAC__FrameHeader mWriteHeader;

    bool init();
    static void copyTrespass();
};

#define ALOGV(...)