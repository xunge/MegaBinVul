#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

typedef struct GF_Box GF_Box;

typedef struct {
    GF_Box *a;
    int is_jp2;
    int method;
    int precedence;
    int approx;
    u8 *opaque;
    u32 opaque_size;
    u32 colour_type;
    u32 colour_primaries;
    u32 transfer_characteristics;
    u32 matrix_coefficients;
    u32 full_range_flag;
} GF_ColourInformationBox;

#define GF_ISOM_SUBTYPE_NCLC 0
#define GF_ISOM_SUBTYPE_NCLX 1
#define GF_ISOM_SUBTYPE_PROF 2
#define GF_ISOM_SUBTYPE_RICC 3

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
void gf_fprintf(FILE *trace, const char *format, ...);
void dump_data_hex(FILE *trace, u8 *data, u32 size);
char *gf_4cc_to_str(u32 type);
void *gf_malloc(size_t size);
u32 gf_base64_encode(const char *in, u32 in_size, char *out, u32 out_size);