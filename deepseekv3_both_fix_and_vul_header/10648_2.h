#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t ut64;

struct r_list_t {
    void *head;
    void *tail;
};
typedef struct r_list_t RList;

struct r_list_iter_t {
    void *data;
    struct r_list_iter_t *n;
    struct r_list_iter_t *p;
};
typedef struct r_list_iter_t RListIter;

struct r_fs_file_t {
    char *name;
    char type;
    ut64 off;
    ut64 size;
    void *data;
};
typedef struct r_fs_file_t RFSFile;

struct r_fs_plugin_t {
    char *name;
    char *desc;
};
typedef struct r_fs_plugin_t RFSPlugin;

struct r_fs_root_t {
    char *path;
    ut64 delta;
    struct r_fs_plugin_t *p;
};
typedef struct r_fs_root_t RFSRoot;

struct r_fs_partition_t {
    int number;
    int type;
    ut64 start;
    ut64 length;
};
typedef struct r_fs_partition_t RFSPartition;

struct r_num_t {
    // dummy definition
};
typedef struct r_num_t RNum;

struct r_fs_t {
    RList *roots;
    RList *plugins;
};
typedef struct r_fs_t RFS;

struct r_core_t {
    RFS *fs;
    ut64 offset;
    RNum *num;
    bool http_up;
};
typedef struct r_core_t RCore;

#define PFMT64x "llx"
#define r_list_foreach(list, it, ptr) for (it = (list)->head; it && (ptr = it->data); it = it->n)

int cmd_mkdir(void *data, const char *input);
int cmd_mv(void *data, const char *input);

void r_cons_printf(const char *fmt, ...);
void eprintf(const char *fmt, ...);
char *r_str_chop_path(char *s);
int r_fs_mount(RFS *fs, const char *fstype, const char *path, ut64 delta);
void r_fs_umount(RFS *fs, const char *path);
char *r_fs_name(RFS *fs, ut64 offset);
RList *r_fs_dir(RFS *fs, const char *path);
RList *r_fs_partitions(RFS *fs, const char *fstype, ut64 delta);
RFSFile *r_fs_open(RFS *fs, const char *path);
void r_fs_read(RFS *fs, RFSFile *file, ut64 addr, ut64 len);
void r_fs_close(RFS *fs, RFSFile *file);
bool r_fs_dir_dump(RFS *fs, const char *path, const char *name);
RList *r_fs_find_name(RFS *fs, const char *name, const char *glob);
RList *r_fs_find_off(RFS *fs, const char *name, ut64 offset);
void r_fs_prompt(RFS *fs, const char *root);
void r_core_cmd_help(RCore *core, const char **help_msg);
ut64 r_num_math(RNum *num, const char *str);
void r_list_free(RList *list);