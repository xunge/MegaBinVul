#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define FILE_HEADER_SIZE 128
#define FILE_ACTIVITY_SIZE 64
#define MIN_FILE_HEADER_SIZE 64
#define MAX_FILE_HEADER_SIZE 1024
#define MAX_FILE_ACTIVITY_SIZE 1024
#define MAX_RECORD_HEADER_SIZE 1024
#define MAX_NR_ACT 64
#define NR_ACT 64
#define NR_MAX 1024
#define NR2_MAX 1024
#define SIZEOF_LONG_64BIT 8
#define ACTIVITY_MAGIC_UNKNOWN 0
#define AO_SELECTED 1
#define HARD_SIZE 1
#define UEOF_STOP 1
#define RESUME_IF_NOT_FOUND 1
#define COUNT_ACTIVITIES 1

struct activity {
    int magic;
    int id;
    int nr_max;
    int gtypes_nr[3];
    int ftypes_nr[3];
    int msize;
    int nr_ini;
    int nr2;
    int fsize;
    int options;
};

struct file_magic {
    unsigned int header_size;
    unsigned int hdr_types_nr;
};

struct file_header {
    int sa_sizeof_long;
    int sa_act_nr;
    unsigned int act_size;
    unsigned int rec_size;
    unsigned int act_types_nr;
    unsigned int rec_types_nr;
    unsigned int extra_next;
};

struct file_activity {
    int id;
    int magic;
    int nr;
    int nr2;
    int size;
    int types_nr[3];
};

#define SREALLOC(ptr, type, size) \
    do { \
        void *new_ptr = realloc(ptr, size); \
        if (!new_ptr) { \
            perror("realloc"); \
            exit(1); \
        } \
        ptr = new_ptr; \
    } while (0)

static inline size_t MAP_SIZE(const int types_nr[3]) {
    return (types_nr[0] + types_nr[1] + types_nr[2]) * sizeof(int);
}

#define IS_SELECTED(options) ((options) & AO_SELECTED)
#define DISPLAY_HDR_ONLY(flags) ((flags) & 0x01)

extern int sa_open_read_magic(int *ifd, char *dfile, struct file_magic *file_magic, int ignore, int *endian_mismatch, int flag);
extern int remap_struct(int hdr_types_nr, unsigned int file_hdr_types_nr, void *buffer, unsigned int src_size, unsigned int dst_size, size_t alloc_size);
extern void swap_struct(int types_nr, void *structure, int arch_64);
extern int get_activity_position(struct activity *act[], int id, int flag);
extern int get_activity_nr(struct activity *act[], int options, int flag);
extern int skip_extra_struct(int ifd, int endian_mismatch, int arch_64);
extern void handle_invalid_sa_file(int ifd, struct file_magic *file_magic, char *dfile, int flag);
extern void sa_fread(int ifd, void *buffer, size_t size, int hard_size, int flag);
extern char *_(const char *str);

static const int hdr_types_nr = 10;
static const int act_types_nr = 10;