#include <stddef.h>

struct mm_struct;
struct cred;

struct fs_struct {
    int lock;
    int users;
};

struct io_kiocb_work {
    struct mm_struct *mm;
    struct cred *creds;
    struct fs_struct *fs;
};

struct io_kiocb {
    struct io_kiocb_work work;
};

static inline void mmdrop(struct mm_struct *mm) {}
static inline void put_cred(struct cred *creds) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void free_fs_struct(struct fs_struct *fs) {}