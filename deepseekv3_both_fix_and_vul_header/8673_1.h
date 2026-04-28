#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define coroutine_fn

typedef struct V9fsPDU {
    int tag;
    int id;
} V9fsPDU;
typedef struct V9fsFidState V9fsFidState;
typedef struct V9fsString {
    char *data;
} V9fsString;

static inline void v9fs_string_init(V9fsString *str) {}
static inline void v9fs_string_free(V9fsString *str) {}
static int pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) { return 0; }
static V9fsFidState *get_fid(V9fsPDU *pdu, int32_t fid) { return NULL; }
static void put_fid(V9fsPDU *pdu, V9fsFidState *fidp) {}
static void pdu_complete(V9fsPDU *pdu, int err) {}
static int v9fs_co_link(V9fsPDU *pdu, V9fsFidState *oldfidp, V9fsFidState *dfidp, V9fsString *name) { return 0; }
static int name_is_illegal(const char *name) { return 0; }
static void trace_v9fs_link(int tag, int id, int dfid, int oldfid, const char *name) {}