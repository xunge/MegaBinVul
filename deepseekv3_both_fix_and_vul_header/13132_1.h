#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned long long ut64;
typedef struct ELFOBJ ELFOBJ;
typedef struct RzVector RzVector;
typedef struct RzBinElfSection RzBinElfSection;

struct RzBinElfSection {
    ut64 offset;
    ut64 rva;
    ut64 size;
    char *name;
};

#define UT64_MAX UINT64_MAX
#define Elf_(x) x
#define RZ_LOG_WARN(x)
#define rz_bin_elf_v2p_new(bin, addr) 0
#define rz_vector_push(v, e) 1