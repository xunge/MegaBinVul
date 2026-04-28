#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ut64;
#define UT64_MAX ULLONG_MAX

typedef struct {
    ut64 offset;
    ut64 rva;
    ut64 size;
    char *name;
} RzBinElfSection;

typedef struct ELFOBJ ELFOBJ;

#define RZ_LOG_WARN(msg)
#define Elf_(x) x
ut64 rz_bin_elf_v2p_new(ELFOBJ *bin, ut64 addr);

typedef struct {
    void *data;
    size_t len;
    size_t capacity;
} RzVector;

void *rz_vector_push(RzVector *vec, void *item);