#include <stdlib.h>
#include <stdio.h>

typedef struct RBinFile {
    void *buf;
} RBinFile;

typedef struct RBinAddr {
    unsigned long long paddr;
    unsigned long long vaddr;
} RBinAddr;

typedef struct RList {
    void *head;
} RList;

typedef struct {
    int pc0;
    int t_addr;
} psxexe_header;

typedef unsigned char ut8;

#define PSXEXE_TEXTSECTION_OFFSET 0
#define R_NEW0(x) calloc(1, sizeof(x))

RList* r_list_new(void);
void r_list_free(RList *list);
void r_list_append(RList *list, void *data);
int r_buf_fread_at(void *buf, int offset, ut8 *dst, const char *fmt, int n);
void eprintf(const char *fmt, ...);