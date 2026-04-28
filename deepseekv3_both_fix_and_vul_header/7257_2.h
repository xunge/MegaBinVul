#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct lmf_record {
    char rec_type;
    char spare;
    short data_nbytes;
} lmf_record;

typedef struct lmf_resource {
    short res1;
    short res2;
    short res3;
    short res4;
} lmf_resource;

typedef struct lmf_data {
    short seg;
    int offset;
} lmf_data;

typedef struct lmf_header {
    // Add necessary fields
} lmf_header;

typedef struct RBinSection {
    char *name;
    ut64 paddr;
    ut64 vaddr;
    ut64 vsize;
    ut64 size;
    bool add;
} RBinSection;

typedef struct RBinReloc {
    ut64 vaddr;
    ut64 paddr;
    char type;
} RBinReloc;

typedef struct RBuffer {
    // minimal definition
} RBuffer;

typedef struct Sdb {
    // minimal definition
} Sdb;

typedef struct RList {
    // minimal definition
} RList;

typedef void (*RListFree)(void *);

typedef struct QnxObj {
    void *kv;
    RList *sections;
    RList *fixups;
    lmf_data rwend;
    lmf_header lmfh;
} QnxObj;

typedef struct RBinFile {
    RBuffer *buf;
} RBinFile;

#define QNX_RECORD_SIZE 4
#define LMF_IMAGE_END_REC 0
#define LMF_RESOURCE_REC 1
#define LMF_LOAD_REC 2
#define LMF_FIXUP_REC 3
#define LMF_8087_FIXUP_REC 4
#define LMF_RW_END_REC 5

#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))

// Function prototypes
RList *r_list_newf(RListFree f);
RList *r_list_new(void);
void r_list_append(RList *list, void *data);
void r_list_free(RList *list);
void r_bin_section_free(RBinSection *ptr);
void *sdb_new0(void);
void sdb_ns_set(Sdb *sdb, const char *name, void *kv);
int r_buf_fread_at(RBuffer *buf, ut64 addr, ut8 *data, const char *fmt, int n);
void lmf_header_load(lmf_header *h, RBuffer *buf, void *kv);