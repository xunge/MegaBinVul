#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef enum {
    TPM_SUCCESS,
    TPM_BAD_PARAMETER,
    TPM_BAD_VERSION,
    TPM_BAD_DATASIZE
} TPM_RESULT;

typedef struct {
    uint32_t totlen;
    uint16_t hdrsize;
    uint16_t flags;
    uint8_t version;
    uint8_t min_version;
} blobheader;

#define BLOB_HEADER_VERSION 1

extern int logprintf(int fd, const char *format, ...);