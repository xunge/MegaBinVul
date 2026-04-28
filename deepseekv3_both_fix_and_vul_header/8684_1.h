#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct V9fsString {
    char *data;
} V9fsString;

typedef struct V9fsQID {
    uint8_t type;
    uint32_t version;
    uint64_t path;
} V9fsQID;

typedef struct V9fsFidState {
    int32_t uid;
    void *path;
} V9fsFidState;

typedef struct V9fsState {
    V9fsQID root_qid;
    int32_t root_fid;
    void *migration_blocker;
    struct {
        char *fs_root;
    } ctx;
    char *tag;
} V9fsState;

typedef struct V9fsPDU {
    V9fsState *s;
    uint16_t tag;
    uint16_t id;
} V9fsPDU;

static void v9fs_string_init(V9fsString *str) {}
static void v9fs_string_free(V9fsString *str) {}
static V9fsFidState *alloc_fid(V9fsState *s, int32_t fid) { return NULL; }
static void clunk_fid(V9fsState *s, int32_t fid) {}
static void put_fid(V9fsPDU *pdu, V9fsFidState *fidp) {}
static ssize_t pdu_unmarshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) { return 0; }
static ssize_t pdu_marshal(V9fsPDU *pdu, size_t offset, const char *fmt, ...) { return 0; }
static void pdu_complete(V9fsPDU *pdu, ssize_t err) {}
static ssize_t v9fs_co_name_to_path(V9fsPDU *pdu, void *arg, const char *path, void **target) { return 0; }
static ssize_t fid_to_qid(V9fsPDU *pdu, V9fsFidState *fidp, V9fsQID *qid) { return 0; }
static void migrate_add_blocker(void *blocker) {}
static void error_setg(void **errp, const char *fmt, ...) {}
static void trace_v9fs_attach(uint16_t tag, uint16_t id, int32_t fid, int32_t afid, const char *uname, const char *aname) {}
static void trace_v9fs_attach_return(uint16_t tag, uint16_t id, uint8_t type, uint32_t version, uint64_t path) {}