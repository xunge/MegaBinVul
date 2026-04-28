#include <stdlib.h>
#include <string.h>

typedef int Id;

typedef struct {
    Id *schematahash;
    Id *schemadata;
    Id *schemata;
    int nschemata;
    int schemadatalen;
} Repodata;

#define SCHEMATADATA_BLOCK 256
#define SCHEMATA_BLOCK 16

extern void *solv_calloc(size_t nmemb, size_t size);
extern void *solv_extend_resize(void *ptr, size_t nmemb, size_t size, size_t block);
extern void *solv_extend(void *ptr, size_t nmemb, size_t ext, size_t size, size_t block);