#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FL_EVALUATE     (1 << 0)
#define FL_CANONICALIZE (1 << 1)
#define FL_NOFSROOT     (1 << 2)
#define FL_RAW          (1 << 3)
#define FL_EXPORT       (1 << 4)
#define FL_JSON         (1 << 5)
#define FL_VFS_ALL      (1 << 6)

#define MS_SHARED      (1 << 0)
#define MS_PRIVATE     (1 << 1)
#define MS_SLAVE       (1 << 2)
#define MS_UNBINDABLE  (1 << 3)

enum {
    COL_SOURCES,
    COL_SOURCE,
    COL_TARGET,
    COL_FSTYPE,
    COL_OPTIONS,
    COL_VFS_OPTIONS,
    COL_FS_OPTIONS,
    COL_OPT_FIELDS,
    COL_UUID,
    COL_PARTUUID,
    COL_LABEL,
    COL_PARTLABEL,
    COL_MAJMIN,
    COL_SIZE,
    COL_AVAIL,
    COL_USED,
    COL_USEPERC,
    COL_FSROOT,
    COL_TID,
    COL_ID,
    COL_PARENT,
    COL_PROPAGATION,
    COL_FREQ,
    COL_PASSNO,
    COL_DELETED
};

struct ul_buffer {
    char *data;
    size_t size;
    size_t allocated;
};

#define UL_INIT_BUFFER { NULL, 0, 0 }

typedef void* blkid_dev_iterate;
typedef void* blkid_dev;
typedef void* blkid_cache;

extern int flags;
extern void *cache;
extern int get_column_id(int num);
extern char *get_tag(struct libmnt_fs *fs, const char *name, int col_id);
extern char *get_vfs_attr(struct libmnt_fs *fs, int col_id);
extern char *xstrdup(const char *s);
extern int xasprintf(char **strp, const char *fmt, ...);
extern void ul_buffer_append_data(struct ul_buffer *buf, const char *data, size_t sz);
extern void ul_buffer_append_string(struct ul_buffer *buf, const char *str);
extern char *ul_buffer_get_data(struct ul_buffer *buf, size_t *sz, size_t *allocated);
extern int blkid_get_cache(blkid_cache *cache, const char *filename);
extern void blkid_probe_all(blkid_cache cache);
extern blkid_dev_iterate blkid_dev_iterate_begin(blkid_cache cache);
extern int blkid_dev_set_search(blkid_dev_iterate iter, const char *search_type, const char *search_value);
extern int blkid_dev_next(blkid_dev_iterate iter, blkid_dev *dev);
extern blkid_dev blkid_verify(blkid_cache cache, blkid_dev dev);
extern const char *blkid_dev_devname(blkid_dev dev);
extern void blkid_dev_iterate_end(blkid_dev_iterate iter);