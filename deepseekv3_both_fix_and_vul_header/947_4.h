#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;
typedef int64_t st64;

#define PFMT64d PRIu64

typedef struct r_bin_t {
    void (*cb_printf)(const char *fmt, ...);
} r_bin_t;

typedef struct RBinFile {
    r_bin_t *rbin;
    struct r_buf_t *buf;
    struct sdb_t *sdb_addrinfo;
} RBinFile;

typedef struct RBinDexObj {
    // Placeholder for DEX object fields
} RBinDexObj;

typedef struct RBinDexClass {
    ut64 source_file;
} RBinDexClass;

typedef struct r_buf_t {
    ut64 length;
    const ut8 *buf;
} r_buf_t;

typedef struct RList {
    // Placeholder for list implementation
} RList;

typedef struct RListIter {
    // Placeholder for list iterator
} RListIter;

typedef struct sdb_t {
    // Placeholder for SDB implementation
} sdb_t;

typedef void (*RListFree)(void *);

struct dex_debug_local_t {
    const char *name;
    char *descriptor;
    ut64 startAddress;
    char *signature;
    bool live;
    int reg;
    ut64 endAddress;
};

struct dex_debug_position_t {
    ut64 source_file_idx;
    ut32 address;
    ut64 line;
};

extern bool dexdump;

#define r_list_foreach(list, it, pos) \
    for((it) = r_list_iterator(list); (pos) = r_list_iter_get(it); r_list_iter_next(it))

extern char* getstr(RBinDexObj *bin, ut64 idx);
extern char* dex_type_descriptor(RBinDexObj *bin, ut64 idx);
extern RList* dex_method_signature2(RBinDexObj *bin, int MI);
extern sdb_t* sdb_new0();
extern void sdb_set(sdb_t *s, const char *k, const char *v, ut32 cas);
extern char* sdb_itoa(ut64 n, char *s, int base);
extern const ut8* r_uleb128(const ut8 *data, int len, ut64 *v);
extern st64 r_sleb128(const ut8 **data, const ut8 *end);
extern RList* r_list_newf(RListFree free);
extern void r_list_free(RList *list);
extern RListIter* r_list_iterator(RList *list);
extern void* r_list_iter_get(RListIter *iter);
extern void r_list_iter_next(RListIter *iter);
extern void r_list_append(RList *list, void *data);
extern char* r_str_newf(const char *fmt, ...);
extern const ut8* r_buf_get_at(r_buf_t *buf, ut64 offset, ut64 *left);