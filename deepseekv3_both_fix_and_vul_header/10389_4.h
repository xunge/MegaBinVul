#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef uint32_t u32;

struct port;
struct scatterlist {
    void *data;
    unsigned int length;
};

extern struct port *find_port_by_vtermno(u32 vtermno);
extern int __send_to_port(struct port *port, struct scatterlist *sg, int nents, int count, void *data, bool flag);
extern int (*early_put_chars)(u32 vtermno, const char *buf, int count);

#define unlikely(x) (x)
#define GFP_ATOMIC 0
#define ENOMEM 1
#define EPIPE 2

static inline void sg_init_one(struct scatterlist *sg, void *data, unsigned int length) {
    sg->data = data;
    sg->length = length;
}

static inline void *kmemdup(const void *src, size_t len, int flags) {
    void *dst = malloc(len);
    if (dst) memcpy(dst, src, len);
    return dst;
}

static inline void kfree(void *p) {
    free(p);
}