#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct VALUE_PAIR {
    struct VALUE_PAIR *next;
} VALUE_PAIR;

typedef struct DICT_VENDOR {
    int type;
    int length;
} DICT_VENDOR;

typedef struct RADIUS_PACKET {
    uint8_t *data;
    int data_len;
    VALUE_PAIR *vps;
} RADIUS_PACKET;

typedef struct radius_packet_t {
    uint8_t data[1];
} radius_packet_t;

#define AUTH_HDR_LEN 20
#define PW_VENDOR_SPECIFIC 26

extern DICT_VENDOR *dict_vendorbyvalue(int vendor);
extern VALUE_PAIR *rad_attr2vp(RADIUS_PACKET *packet, RADIUS_PACKET *original, const char *secret, int attribute, int attrlen, uint8_t *ptr);
extern void pairfree(VALUE_PAIR **vps);
extern void librad_log(const char *msg);
extern void debug_pair(VALUE_PAIR *pair);
extern void lrad_rand_seed(uint8_t *data, int len);