#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    uint32_t net;
    uint8_t node[6];
    uint16_t socket;
} ipx_addr_t;

typedef struct {
    uint8_t type;
    uint8_t direction;
    uint8_t forward;
    union {
        struct {
            uint32_t srcip;
            uint32_t dstip;
            uint8_t srcmask;
            uint8_t dstmask;
            uint8_t proto;
            uint8_t srcPortComp;
            uint8_t dstPortComp;
            uint16_t srcport;
            uint16_t dstport;
            uint8_t established;
        } ip;
        struct {
            ipx_addr_t src;
            ipx_addr_t dst;
            uint8_t srcSocComp;
            uint8_t dstSocComp;
        } ipx;
        struct {
            uint16_t offset;
            uint16_t len;
            uint8_t mask[16];
            uint8_t value[16];
            uint8_t compNeq;
            uint8_t more;
        } generic;
    } u;
} ascend_filter_t;

enum {
    RAD_FILTER_IP,
    RAD_FILTER_IPX,
    RAD_FILTER_GENERIC
};

enum {
    RAD_NO_COMPARE
};

extern const char *fr_int2str(const void *table, int value, const char *def);
extern const void *filterType;
extern const void *filterProtoName;
extern const void *filterCompare;