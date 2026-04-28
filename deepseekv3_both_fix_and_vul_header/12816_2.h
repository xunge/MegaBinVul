#include <cstdint>
#include <set>
#include <stdexcept>

class SPSUnit;
class NALUnit {
public:
    static int deserialize(uint8_t* buffer, uint8_t* end);
};

class BitStreamException : public std::exception {};

enum {
    LT_WARN = 1
};

#define LTRACE(level, sublevel, msg)

class SEIUnit {
private:
    uint8_t* m_nalBuffer;
    int m_nalBufferLen;
    std::set<int> m_processedMessages;
    int pic_struct;

    void sei_payload(SPSUnit& sps, int payloadType, uint8_t* curBuff, int payloadSize, int orig_hrd_parameters_present_flag);
public:
    void deserialize(SPSUnit& sps, int orig_hrd_parameters_present_flag);
};