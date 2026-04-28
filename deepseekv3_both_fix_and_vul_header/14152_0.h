#include <stdint.h>

struct efi_time {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t pad1;
    uint32_t nanosecond;
    int16_t timezone;
    uint8_t daylight;
    uint8_t pad2;
};

static inline uint16_t le32_to_cpu(uint32_t x) {
    return (uint16_t)x;
}