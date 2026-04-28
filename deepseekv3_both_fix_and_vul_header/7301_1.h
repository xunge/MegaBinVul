#include <stdint.h>
#include <arpa/inet.h>

#define AUPRINFO 0x41555052494E464FLL
#define BITSHVTB 0x4249545348565442LL
#define BLACKOUT 0x424C41434B4F5554LL
#define BRANCHPT 0x4252414E43485054LL
#define BUILDVER 0x4255494C44564552LL
#define CORESSMD 0x434F524553534D44LL
#define EXTSS_MD 0x45585453535F4D44LL
#define FILEINFO 0x46494C45494E464FLL
#define NAVI_TBL 0x4E4156495F54424CLL
#define TIMECODE 0x54494D45434F4445LL
#define DTSHDHDR 0x4454534844484452LL
#define AUPR_HDR 0x415550525F484452LL
#define STRMDATA 0x5354524D44415441LL

struct DTSStreamReader {
    bool m_firstCall;
    bool m_isCoreExists;
    int m_skippingSamples;
    int m_dataSegmentLen;
    uint8_t* findFrame(uint8_t* buff, uint8_t* end);
    void checkIfOnlyHDDataExists(uint8_t* buff, uint8_t* end);
};

int64_t my_ntohll(int64_t value);