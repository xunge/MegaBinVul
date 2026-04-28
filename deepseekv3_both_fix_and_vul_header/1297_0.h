#include <sys/types.h>
#include <string.h>

#define FL_INVERT   0x01
#define FL_DF       0x02
#define FL_ALL      0x04
#define FL_REAL     0x08
#define FL_PSEUDO   0x10
#define FL_SHADOWED 0x20
#define FL_DELETED  0x40

enum {
    COL_FSTYPE,
    COL_OPTIONS,
    COL_MAJMIN,
    COL_TARGET,
    COL_SOURCE
};

struct libmnt_fs;
struct libmnt_table;

extern int flags;
extern void *cache;
extern const char *get_match(int col);
extern void *get_match_data(int col);
extern int mnt_fs_match_fstype(struct libmnt_fs *fs, const char *pattern);
extern int mnt_fs_match_options(struct libmnt_fs *fs, const char *pattern);
extern dev_t mnt_fs_get_devno(struct libmnt_fs *fs);
extern int mnt_fs_match_target(struct libmnt_fs *fs, const char *pattern, void *cache);
extern int mnt_fs_match_source(struct libmnt_fs *fs, const char *pattern, void *cache);
extern const char *mnt_fs_get_fstype(struct libmnt_fs *fs);
extern int mnt_fs_is_pseudofs(struct libmnt_fs *fs);
extern int mnt_fs_get_table(struct libmnt_fs *fs, struct libmnt_table **tb);
extern int mnt_table_over_fs(struct libmnt_table *tb, struct libmnt_fs *fs, void *data);
extern int mnt_fs_is_deleted(struct libmnt_fs *fs);