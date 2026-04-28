#include <stdint.h>
#include <string.h>

#define CID_BROADCAST 0xFFFFFFFF
#define U2FHID_INIT 0x86
#define U2FH_OK 0
#define U2FH_TRANSPORT_ERROR 1
#define U2FH_SIZE_ERROR 2
#define U2FH_MEMORY_ERROR 3

typedef struct u2fh_devs u2fh_devs;

struct u2fdevice {
    uint32_t cid;
    uint8_t id;
    uint8_t versionInterface;
    uint8_t versionMajor;
    uint8_t versionMinor;
    uint8_t versionBuild;
    uint8_t capFlags;
};

typedef struct {
    uint8_t nonce[8];
    uint32_t cid;
    uint8_t versionInterface;
    uint8_t versionMajor;
    uint8_t versionMinor;
    uint8_t capFlags;
} U2FHID_INIT_RESP;

extern int obtain_nonce(unsigned char *nonce);
extern int u2fh_sendrecv(u2fh_devs *devs, uint8_t id, uint8_t cmd, const unsigned char *data, size_t datalen, unsigned char *resp, size_t *resplen);