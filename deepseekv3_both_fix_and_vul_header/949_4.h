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

typedef struct RList RList;
typedef struct RListIter RListIter;
typedef void (*RListFree)(void *ptr);

typedef struct RBinFile RBinFile;
typedef struct RBinDexObj RBinDexObj;
typedef struct RBinDexClass RBinDexClass;
typedef struct r_bin_t r_bin_t;
typedef struct RBuffer RBuffer;
typedef struct sdb_t Sdb;

struct RList {
    void *head;
    void *tail;
    RListFree free;
};

struct RListIter {
    void *data;
    RListIter *n;
    RListIter *p;
};

struct RBinFile {
    r_bin_t *rbin;
    RBuffer *buf;
    Sdb *sdb_addrinfo;
};

struct RBinDexClass {
    ut64 source_file;
};

struct r_bin_t {
    void (*cb_printf)(const char *fmt, ...);
};

struct RBuffer {
    const ut8 *buf;
    ut64 length;
};

struct dex_debug_local_t {
    const char *name;
    char *descriptor;
    ut32 startAddress;
    ut32 endAddress;
    const char *signature;
    bool live;
    int reg;
};

struct dex_debug_position_t {
    ut64 source_file_idx;
    ut32 address;
    ut32 line;
};

#define r_list_foreach(list, it, pos) \
    for (it = (list)->head; it && (pos = it->data, 1); it = it->n)

#define PFMT64d PRId64

extern bool dexdump;
extern char* getstr(RBinDexObj *bin, ut64 idx);
extern char* dex_type_descriptor(RBinDexObj *bin, ut64 idx);
extern RList* dex_method_signature2(RBinDexObj *bin, int MI);
extern const ut8* r_buf_get_at(RBuffer *buf, ut64 addr, ut64 *sz);
extern const ut8* r_uleb128(const ut8 *p, int len, ut64 *v);
extern st64 r_sleb128(const ut8 **p, const ut8 *end);
extern char* r_str_newf(const char *fmt, ...);
extern Sdb* sdb_new0();
extern void sdb_set(Sdb *s, const char *k, const char *v, ut32 cas);
extern char* sdb_itoa(ut64 n, char *s, int base);
extern RList* r_list_newf(RListFree free);
extern void r_list_free(RList *list);
extern RListIter* r_list_iterator(RList *list);
extern void r_list_append(RList *list, void *data);