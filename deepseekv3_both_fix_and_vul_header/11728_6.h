#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define NR_MAX 1024
#define DEBUG 1
#define FALSE 0
#define RESUME_IF_NOT_FOUND 0
#define UEOF_CONT 1
#define HARD_SIZE 1
#define HAS_PERSISTENT_VALUES(x) ((x) & 0x01)

typedef unsigned int __nr_t;

struct activity {
    int magic;
    int nr_max;
    int nr_allocated;
    int nr_ini;
    int nr2;
    int msize;
    int fsize;
    __nr_t *nr;
    char **buf;
    char *name;
    int options;
    int ftypes_nr;
    int gtypes_nr;
};

struct file_activity {
    int has_nr;
    __nr_t nr;
    int id;
    int magic;
    int size;
    int nr2;
};

struct file_magic {
    int dummy;
};

void handle_invalid_sa_file(int ifd, struct file_magic *file_magic, char *dfile, int flag);
__nr_t read_nr_value(int ifd, char *dfile, struct file_magic *file_magic, int endian_mismatch, int arch_64, int flag);
int get_activity_position(struct activity *act[], int id, int flag);
void reallocate_all_buffers(struct activity *act, __nr_t nr_value);
int sa_fread(int ifd, char *buf, size_t size, int flag, int oneof);
void swap_struct(int ftypes_nr, char *buf, int arch_64);
void remap_struct(int gtypes_nr, int ftypes_nr, char *buf, int fsize, int msize, ...);