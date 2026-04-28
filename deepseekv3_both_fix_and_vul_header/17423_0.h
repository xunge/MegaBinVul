#include <stdio.h>

typedef int GF_Err;
#define GF_BAD_PARAM 1
#define GF_OK 0

typedef struct GF_Box GF_Box;

typedef struct {
    GF_Box *a;
    int isProtected;
    int Per_Sample_IV_Size;
    int constant_IV_size;
    unsigned char *constant_IV;
    unsigned char KID[16];
    int version;
    int crypt_byte_block;
    int skip_byte_block;
} GF_TrackEncryptionBox;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
void dump_data_hex(FILE *trace, const char *data, int size);