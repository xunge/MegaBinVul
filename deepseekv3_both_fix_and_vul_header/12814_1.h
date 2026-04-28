#include <cstdint>
#include <cstring>

class SPSUnit;

class SEIUnit {
public:
    uint8_t* m_nalBuffer;
    int m_nalBufferLen;
    static const int SEI_MSG_PIC_TIMING = 1;
    static const int SEI_MSG_BUFFERING_PERIOD = 0;
    int removePicTimingSEI(SPSUnit& sps);
};