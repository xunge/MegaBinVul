#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define SENSIBLE_SIZE 8192

typedef long long sf_count_t;

typedef struct
{
    int filedes;
} SF_FILE;

typedef struct
{
    sf_count_t (*write)(const void *, sf_count_t, void *);
    void *user_data;
} SF_VIRTUAL_IO;

typedef struct SF_PRIVATE_tag
{
    int virtual_io;
    SF_VIRTUAL_IO vio;
    SF_FILE file;
    int is_pipe;
    sf_count_t pipeoffset;
    void (*psf_log_syserr)(struct SF_PRIVATE_tag *, int);
    void *vio_user_data;
} SF_PRIVATE;