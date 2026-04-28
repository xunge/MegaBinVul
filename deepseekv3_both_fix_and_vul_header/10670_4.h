#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef struct map_string_t map_string_t;
struct GHashTableIter {
    void *dummy[8];
};

extern char *g_settings_sWatchCrashdumpArchiveDir;
extern unsigned long g_settings_nMaxCrashReportsSize;
extern char *g_settings_dump_location;
extern int g_settings_delete_uploaded;
extern int g_settings_autoreporting;
extern char *g_settings_autoreporting_event;
extern int g_settings_shortenedreporting;
extern int g_settings_privatereports;

#define DEFAULT_DUMP_LOCATION "/var/tmp/abrt-dumps"

char *xstrdup(const char *str);
const char *get_map_string_item_or_NULL(map_string_t *map, const char *key);
void remove_map_string_item(map_string_t *map, const char *key);
int string_to_bool(const char *str);
void error_msg(const char *fmt, ...);
void init_map_string_iter(struct GHashTableIter *iter, map_string_t *map);
int next_map_string_iter(struct GHashTableIter *iter, const char **key, const char **value);

typedef struct GHashTableIter GHashTableIter;