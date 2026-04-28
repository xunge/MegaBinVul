#include <sys/poll.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct pollfd pollfd;

#define POLL_SET_ALLOC_INCREMENT 4

typedef struct {
    pollfd *pollfds;
    unsigned int alloc;
    unsigned int max_used;
    unsigned int used;
    struct {
        unsigned int alloc;
        struct {
            void *value;
        } *table;
    } map;
} poll_set_t;

typedef struct {
    pollfd *pollfd;
} poll_obj_t;

#define m_renew(type, ptr, old_size, new_size) \
    ((type *)realloc(ptr, (new_size) * sizeof(type)))

#define m_new(type, num) \
    ((type *)malloc((num) * sizeof(type)))

#define m_del(type, ptr, num) \
    free(ptr)

#define MP_OBJ_TO_PTR(o) ((void*)(o))
#define mp_uint_t unsigned int
#define mp_map_slot_is_filled(map, index) (1)
#define m_renew_maybe(type, ptr, old_size, new_size, b) m_renew(type, ptr, old_size, new_size)