#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define R_NEW0(x) calloc(1, sizeof(x))
#define PSXEXE_TEXTSECTION_OFFSET 0x800
#define R_PERM_RX 5

typedef struct {
    int t_addr;
    int t_size;
} psxexe_header;

typedef struct RBinSection {
    char *name;
    ut64 paddr;
    ut64 size;
    ut64 vaddr;
    ut64 vsize;
    int perm;
    bool add;
    bool has_strings;
    struct RBinSection *next;
} RBinSection;

typedef struct RBinFile {
    void *buf;
} RBinFile;

typedef struct RList {
    RBinSection *head;
} RList;

static RList* r_list_new(void);
static void r_list_free(RList *list);
static void r_list_append(RList *list, RBinSection *sect);
static int r_buf_fread_at(void *buf, ut64 addr, ut8 *data, const char *fmt, int n);
static ut64 r_buf_size(void *buf);
static void eprintf(const char *fmt, ...);