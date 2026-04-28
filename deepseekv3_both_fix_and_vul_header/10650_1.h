#include <stddef.h>
#include <stdint.h>

typedef int grub_err_t;
typedef unsigned long grub_disk_addr_t;
typedef unsigned long grub_size_t;

struct grub_disk {
    void *data;
};

typedef struct {
    void *io;
    int (*read_at)(void *io, uint64_t offset, uint8_t *buf, int count);
} RIOBind;

typedef uint8_t ut8;

extern RIOBind *bio;
extern uint64_t delta;
extern void eprintf(const char *fmt, ...);