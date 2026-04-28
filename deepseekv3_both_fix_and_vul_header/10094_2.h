#include <stdint.h>
#include <assert.h>
#include <string>

#define WAVE_FORMAT_PCM 0x0001
#define WAVE_FORMAT_IEEE_FLOAT 0x0003
#define WAVE_FORMAT_ALAW 0x0006
#define WAVE_FORMAT_MULAW 0x0007
#define WAVE_FORMAT_EXTENSIBLE 0xFFFE
#define WAVE_FORMAT_ADPCM 0x0002
#define WAVE_FORMAT_DVI_ADPCM 0x0011
#define WAVE_FORMAT_YAMAHA_ADPCM 0x0020
#define WAVE_FORMAT_OKI_ADPCM 0x0010
#define WAVE_FORMAT_CREATIVE_ADPCM 0x0200
#define WAVE_FORMAT_MPEG 0x0050
#define WAVE_FORMAT_MPEGLAYER3 0x0055
#define IBM_FORMAT_MULAW 0x0101
#define IBM_FORMAT_ALAW 0x0102
#define IBM_FORMAT_ADPCM 0x0103

#define AF_BYTEORDER_LITTLEENDIAN 1
#define AF_BYTEORDER_BIGENDIAN 2
#define _AF_BYTEORDER_NATIVE AF_BYTEORDER_LITTLEENDIAN

#define AF_COMPRESSION_NONE 0
#define AF_COMPRESSION_G711_ULAW 1
#define AF_COMPRESSION_G711_ALAW 2
#define AF_COMPRESSION_MS_ADPCM 3
#define AF_COMPRESSION_IMA 4

#define AF_SAMPFMT_UNSIGNED 0
#define AF_SAMPFMT_TWOSCOMP 1
#define AF_SAMPFMT_FLOAT 2
#define AF_SAMPFMT_DOUBLE 3

#define AF_FAIL 0
#define AF_SUCCEED 1

#define AF_BAD_CHANNELS 1
#define AF_BAD_WIDTH 2
#define AF_BAD_HEADER 3
#define AF_BAD_NOT_IMPLEMENTED 4
#define AF_BAD_CODEC_CONFIG 5

#define _AF_MS_ADPCM_NUM_COEFFICIENTS 1
#define _AF_MS_ADPCM_COEFFICIENTS 2

#define AU_PVTYPE_LONG 1
#define AU_PVTYPE_PTR 2

typedef int status;

struct UUID {
    uint32_t data[4];
    std::string name() const { return ""; }
    bool operator==(const UUID& other) const {
        return data[0] == other.data[0] && data[1] == other.data[1] &&
               data[2] == other.data[2] && data[3] == other.data[3];
    }
};

struct Tag {
};

struct Track {
    struct {
        int channelCount;
        int sampleRate;
        int byteOrder;
        int compressionType;
        int framesPerPacket;
        int sampleWidth;
        int sampleFormat;
        int bytesPerPacket;
        void* compressionParams;
        
        bool isUncompressed();
        void computeBytesPerPacketPCM();
    } f;
};

class WAVEFile {
public:
    status parseFormat(const Tag &id, uint32_t size);
    Track* getTrack();
    void readU16(uint16_t*);
    void readU32(uint32_t*);
    void readS16(int16_t*);
    void readUUID(UUID*);
    void _af_error(int, const char*, ...);
    void _af_set_sample_format(void*, int, int);
    void initIMACompressionParams();
    
    int m_msadpcmNumCoefficients;
    int16_t m_msadpcmCoefficients[256][2];
};

typedef void* AUpvlist;
AUpvlist AUpvnew(int);
void AUpvsetparam(AUpvlist, int, int);
void AUpvsetvaltype(AUpvlist, int, int);
void AUpvsetval(AUpvlist, int, void*);

extern UUID _af_wave_guid_pcm;
extern UUID _af_wave_guid_ieee_float;
extern UUID _af_wave_guid_alaw;
extern UUID _af_wave_guid_ulaw;