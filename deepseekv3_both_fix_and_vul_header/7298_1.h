#include <stdint.h>
#include <arpa/inet.h>

class DTSStreamReader {
public:
    bool m_firstCall;
    bool m_isCoreExists;
    uint32_t m_skippingSamples;
    uint64_t m_dataSegmentLen;
    
    uint8_t* findFrame(uint8_t* buff, uint8_t* end);
    void checkIfOnlyHDDataExists(uint8_t* buff, uint8_t* end);
};

#define AUPRINFO 0x41555052494E464FULL
#define BITSHVTB 0x4249545348565442ULL
#define BLACKOUT 0x424C41434B4F5554ULL
#define BRANCHPT 0x4252414E43485054ULL
#define BUILDVER 0x4255494C44564552ULL
#define CORESSMD 0x434F524553534D44ULL
#define EXTSS_MD 0x45585453535F4D44ULL
#define FILEINFO 0x46494C45494E464FULL
#define NAVI_TBL 0x4E4156495F54424CULL
#define TIMECODE 0x54494D45434F4445ULL
#define DTSHDHDR 0x4454534844484452ULL
#define AUPR_HDR 0x415550525F484452ULL
#define STRMDATA 0x5354524D44415441ULL

uint64_t my_ntohll(uint64_t value);