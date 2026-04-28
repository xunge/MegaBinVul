#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define SIZE_MAX ((size_t)-1)

struct snd_compr_stream;
struct snd_compr_params;

struct snd_compr_params {
    struct {
        unsigned int fragment_size;
        unsigned int fragments;
    } buffer;
};

struct snd_compr_stream {
    struct {
        unsigned int fragment_size;
        unsigned int fragments;
        void *buffer;
        unsigned int buffer_size;
    } *runtime;
    struct {
        int (*copy)(void);
    } *ops;
};

void *kmalloc(size_t size, int flags);