#include <stdint.h>

#define NOT_ENOUGH_BUFFER -1

class NALUnit {
public:
    static int deserialize(uint8_t* buffer, uint8_t* end);
};

class BitStreamException {};

class SEIUnit {
private:
    uint8_t* m_nalBuffer;
    int m_nalBufferLen;
    int pic_struct;
public:
    int isMVCSEI();
};