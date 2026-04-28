#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef size_t INTERNAL_SIZE_T;
#define SIZE_MAX ((size_t)-1)
#define MINSIZE (sizeof(struct malloc_chunk))

struct malloc_chunk {
    INTERNAL_SIZE_T prev_size;
    INTERNAL_SIZE_T size;
    struct malloc_chunk* fd;
    struct malloc_chunk* bk;
};

typedef struct malloc_chunk* mchunkptr;
#define NON_MAIN_ARENA 0x4
#define IS_MMAPPED 0x2
#define PREV_INUSE 0x1

struct malloc_state {
    int flags;
};
typedef struct malloc_state* mstate;
extern struct malloc_state main_arena;

#define chunksize(p) ((p)->size & ~(0x1|0x2|0x4))
#define chunk_is_mmapped(p) ((p)->size & IS_MMAPPED)
#define prev_size(p) ((p)->prev_size)
#define set_prev_size(p, sz) ((p)->prev_size = (sz))
#define set_head(p, sz) ((p)->size = (sz))
#define set_head_size(p, sz) ((p)->size = (((p)->size & 0x7) | (sz)))
#define set_inuse_bit_at_offset(p, s) 
#define chunk_at_offset(p, s) ((mchunkptr)(((char*)(p)) + (s)))
#define chunk2mem(p) ((void*)((char*)(p) + 2*sizeof(INTERNAL_SIZE_T)))
#define mem2chunk(mem) ((mchunkptr)((char*)(mem) - 2*sizeof(INTERNAL_SIZE_T)))

void __set_errno(int);
void* _int_malloc(mstate, size_t);
void _int_free(mstate, void*, int);
void checked_request2size(size_t, INTERNAL_SIZE_T*);
void check_inuse_chunk(mstate, mchunkptr);