#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

typedef struct UnitVTable UnitVTable;
typedef struct Meta Meta;
typedef struct Unit Unit;

struct UnitVTable {
    int (*load)(Unit *u);
};

struct Meta {
    bool in_load_queue;
    int type;
    int load_state;
    int load_error;
    bool default_dependencies;
    bool on_failure_isolate;
    char *id;
    Unit *merged_into;
    Unit *manager;
    void *dependencies[1];
};

struct Unit {
    Meta meta;
    UnitVTable *vtable;
};

#define _UNIT_TYPE_INVALID 0
#define UNIT_STUB 0
#define UNIT_LOADED 1
#define UNIT_ERROR 2
#define UNIT_MERGED 3
#define UNIT_ON_FAILURE 0

#define UNIT_VTABLE(u) ((UnitVTable*)u->vtable)
#define LIST_REMOVE(type, member, head, item) 

int unit_add_default_dependencies(Unit *u);
int unit_add_to_dbus_queue(Unit *u);
int unit_add_to_gc_queue(Unit *u);
Unit* unit_follow_merge(Unit *u);
void log_error(const char *format, ...);
void log_debug(const char *format, ...);
size_t set_size(void *set);