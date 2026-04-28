#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef char gchar;

struct _GString {
    char *str;
    size_t len;
};
typedef struct _GString GString;

struct dm_task;
struct dm_info {
    int exists;
    int target_count;
};

#define DM_DEVICE_TABLE 0
#define G_GUINT64_FORMAT "lu"

GString *g_string_new(const char *init);
void g_string_free(GString *string, gboolean free_segment);
void g_string_append(GString *string, const char *val);
void g_string_append_c(GString *string, char c);
void g_string_append_printf(GString *string, const char *format, ...);
void g_print(const char *format, ...);

struct dm_task *dm_task_create(int type);
int dm_task_set_major(struct dm_task *dmt, int major);
int dm_task_set_minor(struct dm_task *dmt, int minor);
int dm_task_run(struct dm_task *dmt);
int dm_task_get_info(struct dm_task *dmt, struct dm_info *info);
const char *dm_task_get_name(struct dm_task *dmt);
void dm_task_destroy(struct dm_task *dmt);
void *dm_get_next_target(struct dm_task *dmt, void *next, uint64_t *start, uint64_t *length, char **target_type, char **params);

void _udev_util_encode_string(const char *src, char *dest, size_t dest_len);