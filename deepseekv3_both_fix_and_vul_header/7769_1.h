#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define R_MAX(a, b) ((a) > (b) ? (a) : (b))
#define R_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    ut64 vaddr;
    size_t vsize;
} Section;

typedef struct {
    Section *_const;
    Section *_selrefs;
    size_t file_size;
    size_t word_size;
    struct {
        struct {
            struct {
                bool verbose;
            } *bin;
            void *io;
        } *core;
    };
} RCoreObjc;

static ut64 r_read_le64(const ut8 *buf) {
    return *(ut64 *)buf;
}

static bool isValid(ut64 addr) {
    return addr != 0;
}

static void array_add(RCoreObjc *objc, ut64 va, ut64 xrefs_to) {
    // dummy implementation
}

static int r_io_read_at(void *io, ut64 addr, ut8 *buf, size_t len) {
    // dummy implementation
    return 1;
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)