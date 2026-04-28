#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#define RZ_PERM_R 4
#define RZ_PERM_W 2
#define RZ_PERM_X 1
#define RZ_PERM_RX (RZ_PERM_R | RZ_PERM_X)
#define PFMT64x "lx"
#define PROC_NAME_SZ 1023
#define PROC_REGION_SZ 99
#define PROC_PERM_SZ 4
#define PROC_REGION_LEFT_SZ (PROC_REGION_SZ - 2)
#define RZ_STR_DEF(x) #x

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct rz_debug_map_t {
    char *name;
    ut64 addr;
    ut64 addr_end;
    int perm;
    ut64 offset;
    bool shared;
    char *file;
} RzDebugMap;

typedef struct rz_list_t {
    void *head;
} RzList;

typedef struct gdbr_desc_t {
    int pid;
    bool get_baddr;
    int (*open_file)(struct gdbr_desc_t *, const char *, int, int);
    int (*close_file)(struct gdbr_desc_t *);
    int (*read_file)(struct gdbr_desc_t *, ut8 *, ut64);
    ut64 (*get_baddr_func)(struct gdbr_desc_t *);
} gdbr_desc_t;

typedef struct rz_debug_gdb_ctx_t {
    gdbr_desc_t *desc;
} RzDebugGdbCtx;

typedef struct rz_debug_t {
    void *plugin_data;
} RzDebug;

extern void check_connection(RzDebug *dbg);
extern RzList *rz_list_new(void);
extern void rz_list_free(RzList *list);
extern int rz_list_append(RzList *list, void *data);
extern RzDebugMap *rz_debug_map_new(const char *name, ut64 addr, ut64 addr_end, int perm, ut64 offset);
extern ut64 rz_num_get(void *user, const char *str);
extern void eprintf(const char *format, ...);
extern ut64 gdbr_get_baddr(gdbr_desc_t *desc);
extern int gdbr_open_file(gdbr_desc_t *desc, const char *path, int flags, int mode);
extern int gdbr_close_file(gdbr_desc_t *desc);
extern int gdbr_read_file(gdbr_desc_t *desc, ut8 *buf, ut64 len);