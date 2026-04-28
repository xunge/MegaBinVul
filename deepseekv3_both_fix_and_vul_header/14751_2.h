#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef int status_t;
#define ERROR_MALFORMED (-1)
#define OK 0

#define kTag_DecoderConfigDescriptor 0x04
#define ALOGW printf

class ESDS {
public:
    const uint8_t* mData;
    status_t skipDescriptorHeader(size_t offset, size_t size, uint8_t* tag, size_t* sub_offset, size_t* sub_size);
    status_t parseDecoderConfigDescriptor(size_t sub_offset, size_t sub_size);
    status_t parseESDescriptor(size_t offset, size_t size);
};