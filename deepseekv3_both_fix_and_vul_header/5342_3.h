#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ZVOL_DIR "/dev/zvol"
#define SDEV_VATTR 0
#define RW_READER 0
#define ZFS_IOC_DATASET_LIST_NEXT 0

struct vnode {
    void *v_data;
};

struct uio {
    off_t uio_offset;
};

struct cred;

typedef void* caller_context_t;

struct sdev_node {
    char *sdev_path;
    char *sdev_name;
    int sdev_contents;
};

#define VTOSDEV(vp) ((struct sdev_node *)(vp)->v_data)

static void sdcmn_err13(const char *fmt, ...) {}
static int devname_lookup_func(struct sdev_node *a, const char *b, struct vnode **c, struct cred *d, int (*e)(), int f) { return 0; }
static void VN_RELE(struct vnode *a) {}
static int devname_readdir_func(struct vnode *a, struct uio *b, struct cred *c, int *d, int e) { return 0; }
static void devzvol_prunedir(struct sdev_node *a) {}
static void devzvol_create_pool_dirs(struct vnode *a) {}
static int sdev_iter_datasets(struct vnode *a, int b, const char *c) { return 0; }
static int devzvol_create_dir(struct sdev_node *a, const char *b, struct vnode **c, struct cred *d, int e) { return 0; }
static void rw_exit(int *a) {}
static void rw_enter(int *a, int b) {}