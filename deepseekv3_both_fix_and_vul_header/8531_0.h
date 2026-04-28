#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef int BOOL;
#define FALSE 0
#define TRUE 1

typedef unsigned char BYTE;
typedef uint16_t UINT16;

typedef struct _STREAM STREAM;
struct _STREAM {
    BYTE* p;
    size_t size;
};

typedef struct _rdpRdp rdpRdp;
struct _rdpRdp {
    struct {
        int EncryptionMethods;
    }* settings;
};

#define ENCRYPTION_METHOD_FIPS 1
#define SEC_SECURE_CHECKSUM 1

BOOL security_fips_decrypt(BYTE* data, int length, rdpRdp* rdp);
BOOL security_fips_check_signature(BYTE* data, int length, BYTE* sig, rdpRdp* rdp);
BOOL security_decrypt(BYTE* data, int length, rdpRdp* rdp);
void security_salted_mac_signature(rdpRdp* rdp, BYTE* data, int length, BOOL encryption, BYTE* output);
void security_mac_signature(rdpRdp* rdp, BYTE* data, int length, BYTE* output);

void stream_read_UINT16(STREAM* s, UINT16 val);
void stream_read_BYTE(STREAM* s, BYTE val);
void stream_seek(STREAM* s, size_t offset);
void stream_read(STREAM* s, void* data, size_t size);
size_t stream_get_left(STREAM* s);