#include <cstdint>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using std::make_pair;

struct CheckStreamRez {
    std::string codecInfo;
    std::string streamDescr;
    bool multiSubStream;
};

struct NALUnit {
    enum NALType {
        nuSPS,
        nuSubSPS,
        nuPPS,
        nuSEI,
        nuSliceIDR,
        nuSliceNonIDR,
        nuSliceA,
        nuSliceB,
        nuSliceC,
        nuSliceExt
    };
    static uint8_t* findNextNAL(uint8_t* buffer, uint8_t* end);
    static const uint8_t* findNALWithStartCode(const uint8_t* buffer, const uint8_t* end, bool withStartCode);
};

struct SEIUnit {
    int pic_struct;
    int number_of_offset_sequences;
    void decodeBuffer(const uint8_t* buffer, const uint8_t* end);
    void deserialize(const struct SPSUnit& sps, bool hrdPresent);
};

struct SliceUnit {
    static int decodeNAL(const uint8_t* buffer, const uint8_t* end, uint8_t* outBuffer, int outSize);
    int deserialize(const uint8_t* buffer, const uint8_t* end, const std::map<int, struct SPSUnit*>& spsMap, const std::map<int, struct PPSUnit*>& ppsMap);
};

struct SPSUnit {
    int seq_parameter_set_id;
    struct {
        bool isPresent;
    } nalHrdParams, vclHrdParams;
    void decodeBuffer(const uint8_t* buffer, const uint8_t* end);
    int deserialize();
    std::string getStreamDescr();
};

struct PPSUnit {
    int pic_parameter_set_id;
    int seq_parameter_set_id;
    void decodeBuffer(const uint8_t* buffer, const uint8_t* end);
    int deserialize();
};

struct BitStreamException {};

class H264StreamReader {
public:
    bool m_eof;
    bool m_mvcSubStream;
    bool m_mvcPrimaryStream;
    std::map<int, SPSUnit*> m_spsMap;
    std::map<int, PPSUnit*> m_ppsMap;
    CheckStreamRez checkStream(uint8_t* buffer, int len);
};

extern std::string h264CodecInfo;
extern std::string h264DepCodecInfo;

std::string int32ToStr(int32_t value);

#define FFMIN(a,b) ((a) > (b) ? (b) : (a))