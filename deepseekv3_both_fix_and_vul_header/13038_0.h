#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IO_MAPS_PERM_SZ 31
#define IO_MAPS_NAME_SZ 511
#define PFMT64x "llx"
#define RZ_STR_DEF(x) #x

typedef unsigned long long ut64;

typedef struct {
    void *io;
    char *(*system)(void *io, const char *cmd);
} RzIOBind;

typedef struct {
    RzIOBind iob;
} RzDebug;

typedef struct {
    char *name;
    ut64 start;
    ut64 end;
    int perm;
    int user;
} RzDebugMap;

typedef struct rz_list_t {
    void *data;
    struct rz_list_t *next;
} RzList;

RzList *rz_list_new();
void rz_list_free(RzList *list);
void rz_list_append(RzList *list, void *data);
RzDebugMap *rz_debug_map_new(const char *name, ut64 start, ut64 end, int perm, int user);
int rz_str_rwx(const char *str);
void rz_cons_reset();