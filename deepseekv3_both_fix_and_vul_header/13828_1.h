#include <string.h>
#include <stddef.h>

#define RADIUS_VECTOR_LEN 16
#define RADIUS_PASSWD_LEN 16
#define PR_TUNABLE_BUFFER_SIZE 128
#define RADIUS_PASSWORD 2
#define RADIUS_OLD_PASSWORD 3

typedef struct MD5_CTX {
    unsigned char data[64];
    unsigned int state[4];
    unsigned int count[2];
} MD5_CTX;

typedef struct radius_packet radius_packet_t;
typedef struct radius_attrib radius_attrib_t;

struct radius_attrib {
    unsigned char *data;
};

struct radius_packet {
    unsigned char *digest;
};

void MD5_Init(MD5_CTX *ctx);
void MD5_Update(MD5_CTX *ctx, const unsigned char *data, size_t len);
void MD5_Final(unsigned char *digest, MD5_CTX *ctx);

radius_attrib_t *radius_get_attrib(radius_packet_t *packet, unsigned char type);
void radius_add_attrib(radius_packet_t *packet, unsigned char type, const unsigned char *value, size_t len);
void radius_xor(unsigned char *out, const unsigned char *in, size_t len);
void pr_memscrub(void *buf, size_t bufsz);