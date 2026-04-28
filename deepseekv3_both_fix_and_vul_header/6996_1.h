#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ut8;
typedef unsigned long long ut64;

typedef struct Sdb Sdb;

typedef struct {
    char *name;
    ut64 id_idx;
    ut64 mod_time;
    ut64 file_len;
} file_entry;

typedef struct RBinDwarfLineHeader {
    file_entry *file_names;
    size_t file_names_count;
} RBinDwarfLineHeader;

typedef struct RBinFile {
    Sdb *sdb_addrinfo;
} RBinFile;

typedef int (*PrintfCallback)(const char *format, ...);

#define R_MODE_PRINT 1
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))
#define R_FREE(x) { free(x); x = NULL; }
#define PFMT64d "llu"

size_t r_str_nlen(const char *str, size_t maxlen);
char *r_str_ndup(const char *str, size_t len);
const ut8 *r_uleb128(const ut8 *data, size_t len, ut64 *v, const ut8 *end);
char *r_str_newf(const char *fmt, ...);
const char *r_str_get(const char *str);

void add_sdb_include_dir(Sdb *sdb, const char *str, int i);
char *sdb_array_get(Sdb *sdb, const char *key, int idx, int *ok);
char *sdb_get(Sdb *sdb, const char *key, int *ok);
void sdb_free(Sdb *sdb);