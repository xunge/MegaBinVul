#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MIN_FILE_HEADER_SIZE 0
#define MAX_FILE_HEADER_SIZE 0
#define MAX_NR_ACT 0
#define MAX_FILE_ACTIVITY_SIZE 0
#define MAX_RECORD_HEADER_SIZE 0
#define NR_MAX 0
#define NR2_MAX 0
#define NR_ACT 0
#define SIZEOF_LONG_64BIT 0
#define FILE_HEADER_SIZE 0
#define FILE_ACTIVITY_SIZE 0
#define ACTIVITY_MAGIC_UNKNOWN 0
#define HARD_SIZE 0
#define UEOF_STOP 0
#define AO_SELECTED 0
#define RESUME_IF_NOT_FOUND 0
#define COUNT_ACTIVITIES 0
#define DISPLAY_HDR_ONLY(x) 0
#define IS_SELECTED(x) 0
#define MAP_SIZE(x) 0
#define SREALLOC(p, type, size) do { void *tmp = realloc(p, size); if (tmp) p = tmp; } while (0)

static const unsigned int hdr_types_nr = 0;
static const unsigned int act_types_nr = 0;

struct activity {
    int magic;
    int nr_max;
    int gtypes_nr[3];
    int ftypes_nr[3];
    int msize;
    int nr_ini;
    int nr2;
    int fsize;
    int id;
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
};

struct file_activity {
    int id;
    int magic;
    int nr;
    int nr2;
    int size;
    int types_nr[3];
};

extern int sa_open_read_magic(int *ifd, char *dfile, struct file_magic *file_magic, int ignore, int *endian_mismatch, int flag);
extern void sa_fread(int fd, void *buf, size_t count, int hard_size, int ueof_stop);
extern int remap_struct(unsigned int types_nr, unsigned int hdr_types_nr, void *buffer, unsigned int src_size, unsigned int dst_size, unsigned int header_size);
extern void swap_struct(unsigned int types_nr, void *structure, int arch_64);
extern int get_activity_position(struct activity *act[], int id, int resume_if_not_found);
extern void handle_invalid_sa_file(int fd, struct file_magic *file_magic, char *dfile, int flag);
extern int get_activity_nr(struct activity *act[], int options, int count_activities);
extern char *_(const char *str);