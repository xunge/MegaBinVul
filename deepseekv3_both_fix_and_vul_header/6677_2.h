#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct ID3 {
    size_t mSize;
    uint8_t* mData;
    bool removeUnsynchronizationV2_4(bool iTunesHack);
};

uint32_t U32_AT(const uint8_t* ptr);
uint16_t U16_AT(const uint8_t* ptr);
bool ParseSyncsafeInteger(const uint8_t* data, size_t* size);
void WriteSyncsafeInteger(uint8_t* data, size_t value);
void android_errorWriteLog(uint32_t tag, const char* subTag);
#define ALOGE(...)