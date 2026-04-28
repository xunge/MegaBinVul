#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool mrb_bool;
#define TRUE true
#define FALSE false

typedef struct mrb_state mrb_state;

struct RBasic {
    uint32_t tt;
    struct RClass *c;
    struct RBasic *gcnext;
};

struct RClass {
    struct RBasic basic;
    // Other members omitted
};

struct RData {
    struct RBasic basic;
    void (*dfree)(void*);
    void *data;
    struct RClass *type;
};

typedef struct {
    union {
        uintptr_t w;
        void *p;
        struct RBasic *bp;
    } value;
    struct RBasic *c;
} mrb_value;

struct mrb_io {
    int fd;
    int fd2;
    int pid;
    bool readable;
    bool writable;
    bool sync;
    bool is_socket;
};

extern struct RClass *mrb_io_type;

static inline void *mrb_ptr(mrb_value v) { return v.value.p; }
#define DATA_PTR(v) (((struct RData*)mrb_ptr(v))->data)
#define DATA_TYPE(v) (((struct RData*)mrb_ptr(v))->type)

void fptr_finalize(mrb_state *mrb, struct mrb_io *fptr, mrb_bool flag);
struct mrb_io *mrb_io_alloc(mrb_state *mrb);
struct mrb_io *io_get_open_fptr(mrb_state *mrb, mrb_value obj);
int mrb_dup(mrb_state *mrb, int fd, mrb_bool *failed);
void mrb_fd_cloexec(mrb_state *mrb, int fd);
void mrb_sys_fail(mrb_state *mrb, int err);
mrb_value mrb_iv_get(mrb_state *mrb, mrb_value obj, int sym);
void mrb_iv_set(mrb_state *mrb, mrb_value obj, int sym, mrb_value val);
int mrb_intern_cstr(mrb_state *mrb, const char *str);
void mrb_free(mrb_state *mrb, void *ptr);
void mrb_get_args(mrb_state *mrb, const char *format, ...);