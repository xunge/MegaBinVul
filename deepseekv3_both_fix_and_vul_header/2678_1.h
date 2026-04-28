#include <time.h>
#include <stddef.h>

typedef long long time64_t;
#define ASN1_UNITIM 0x17
#define ASN1_GENTIM 0x18
#define EBADMSG 74

static inline time64_t mktime64(unsigned int year, unsigned int mon,
                              unsigned int day, unsigned int hour,
                              unsigned int min, unsigned int sec) {
    struct tm tm = {
        .tm_year = year - 1900,
        .tm_mon = mon - 1,
        .tm_mday = day,
        .tm_hour = hour,
        .tm_min = min,
        .tm_sec = sec
    };
    return (time64_t)mktime(&tm);
}

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)