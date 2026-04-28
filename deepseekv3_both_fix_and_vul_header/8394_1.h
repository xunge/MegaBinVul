#include <stdint.h>
#include <vector>
#include <string>
#include <cstring>

struct HDRStaticInfo {
    uint8_t data[25];
};

class ABuffer {
public:
    size_t size() const;
    void* data() const;
};

class AString {
public:
    const char* c_str() const;
    bool startsWith(const char* prefix) const;
    bool operator==(const char* str) const;
};

template<typename T>
class sp {
    T* m_ptr;
public:
    T* operator->() const { return m_ptr; }
};

class AMessage {
public:
    bool findString(const char* name, AString* value) const;
    bool findInt64(const char* name, int64_t* value) const;
    bool findInt32(const char* name, int32_t* value) const;
    bool findFloat(const char* name, float* value) const;
    bool findRect(const char* name, int32_t* left, int32_t* top, int32_t* right, int32_t* bottom) const;
    bool findBuffer(const char* name, sp<ABuffer>* buffer) const;
    bool contains(const char* name) const;
};

class MetaData {
public:
    void setCString(uint32_t key, const char* value);
    void setInt64(uint32_t key, int64_t value);
    void setInt32(uint32_t key, int32_t value);
    void setRect(uint32_t key, int32_t left, int32_t top, int32_t right, int32_t bottom);
    void setData(uint32_t key, uint32_t type, const void* data, size_t size);
};

namespace ColorUtils {
    bool getHDRStaticInfoFromFormat(const sp<AMessage>& msg, HDRStaticInfo* info);
}

void convertMessageToMetaDataColorAspects(const sp<AMessage>& msg, sp<MetaData>& meta);

size_t reassembleAVCC(const sp<ABuffer>& csd0, const sp<ABuffer>& csd1, void* out);
void reassembleESDS(const sp<ABuffer>& csd0, void* out);
size_t reassembleHVCC(const sp<ABuffer>& csd0, void* out, size_t outSize, int nalLengthSize);

constexpr uint32_t kKeyMIMEType = 0;
constexpr uint32_t kKeyDuration = 0;
constexpr uint32_t kKeyIsSyncFrame = 0;
constexpr uint32_t kKeyBitRate = 0;
constexpr uint32_t kKeyMaxBitRate = 0;
constexpr uint32_t kKeyWidth = 0;
constexpr uint32_t kKeyHeight = 0;
constexpr uint32_t kKeySARWidth = 0;
constexpr uint32_t kKeySARHeight = 0;
constexpr uint32_t kKeyColorFormat = 0;
constexpr uint32_t kKeyCropRect = 0;
constexpr uint32_t kKeyRotation = 0;
constexpr uint32_t kKeyHdrStaticInfo = 0;
constexpr uint32_t kKeyChannelCount = 0;
constexpr uint32_t kKeySampleRate = 0;
constexpr uint32_t kKeyChannelMask = 0;
constexpr uint32_t kKeyEncoderDelay = 0;
constexpr uint32_t kKeyEncoderPadding = 0;
constexpr uint32_t kKeyIsADTS = 0;
constexpr uint32_t kKeyPcmEncoding = 0;
constexpr uint32_t kKeyMaxInputSize = 0;
constexpr uint32_t kKeyMaxWidth = 0;
constexpr uint32_t kKeyMaxHeight = 0;
constexpr uint32_t kKeyFrameRate = 0;
constexpr uint32_t kKeyAVCC = 0;
constexpr uint32_t kKeyESDS = 0;
constexpr uint32_t kKeyHVCC = 0;
constexpr uint32_t kKeyVp9CodecPrivate = 0;
constexpr uint32_t kKeyOpusHeader = 0;
constexpr uint32_t kKeyOpusCodecDelay = 0;
constexpr uint32_t kKeyOpusSeekPreRoll = 0;
constexpr uint32_t kKeyVorbisInfo = 0;
constexpr uint32_t kKeyVorbisBooks = 0;
constexpr uint32_t kKeyTimeScale = 0;

const char* MEDIA_MIMETYPE_VIDEO_AVC = "video/avc";
const char* MEDIA_MIMETYPE_AUDIO_AAC = "audio/aac";
const char* MEDIA_MIMETYPE_VIDEO_MPEG4 = "video/mp4v-es";
const char* MEDIA_MIMETYPE_VIDEO_HEVC = "video/hevc";
const char* MEDIA_MIMETYPE_VIDEO_VP9 = "video/x-vnd.on2.vp9";
const char* MEDIA_MIMETYPE_AUDIO_OPUS = "audio/opus";
const char* MEDIA_MIMETYPE_AUDIO_VORBIS = "audio/vorbis";

#define ALOGW(...)