#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <elf.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

#define R_BIN_ELF64 0
#define READ16(p, i) (i += 2, (p[i-2] | (p[i-1] << 8)))
#define READ32(p, i) (i += 4, (p[i-4] | (p[i-3] << 8) | (p[i-2] << 16) | (p[i-1] << 24)))
#define READ64(p, i) (i += 8, ((ut64)p[i-8] | ((ut64)p[i-7] << 8) | ((ut64)p[i-6] << 16) | ((ut64)p[i-5] << 24) | ((ut64)p[i-4] << 32) | ((ut64)p[i-3] << 40) | ((ut64)p[i-2] << 48) | ((ut64)p[i-1] << 56)))

typedef struct ELFOBJ {
    void *b;
    void *kv;
    int endian;
    Elf32_Ehdr ehdr;
} ELFOBJ;

typedef struct sdb_t {
    void *kv;
} sdb_t;

void sdb_set(sdb_t *s, const char *k, const char *v, int n);
void sdb_num_set(sdb_t *s, const char *k, ut64 n, int o);
bool __is_valid_ident(ELFOBJ *bin);
int r_buf_read_at(void *b, ut64 addr, ut8 *buf, int len);
void R_LOG_ERROR(const char *msg);

#define Elf_(x) Elf32_##x