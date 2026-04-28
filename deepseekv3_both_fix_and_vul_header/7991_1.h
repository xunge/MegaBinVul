#include <stdint.h>
#include <stdbool.h>

struct ATSParser {
    struct PSISection {
        bool isComplete() const;
        uint8_t* data();
        unsigned mSkipBytes;
        struct Buffer {
            uint8_t* data();
        } *mBuffer;
        bool isCRCOkay() const;
    };
};

#define U16_AT(x) (((x)[0] << 8) | (x)[1])
#define ALOGV(...)
#define ALOGE(...)
#define android_errorWriteLog(...)

static const uint32_t CRC_TABLE[256] = {
    0x00000000, 0x04C11DB7, 0x09823B6E, 0x0D4326D9, 0x130476DC, 0x17C56B6B, 0x1A864DB2, 0x1E475005,
    0x2608EDB8, 0x22C9F00F, 0x2F8AD6D6, 0x2B4BCB61, 0x350C9B64, 0x31CD86D3, 0x3C8EA00A, 0x384FBDBD
};