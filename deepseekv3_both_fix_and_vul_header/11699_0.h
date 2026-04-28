#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

typedef struct vrrp_tracked_file {
    char *file_path;
    char *fname;
} vrrp_tracked_file_t;

typedef struct list {
    void *tail;
} list;

typedef struct vrrp_data {
    list *vrrp_track_files;
} vrrp_data_t;

extern vrrp_data_t *vrrp_data;
extern int track_file_init;
extern int track_file_init_value;
extern bool reload;
extern unsigned long debug;

#define CONFIG_GENERAL_ERROR 0
#define TRACK_FILE_NO_INIT 0
#define TRACK_FILE_CREATE 1
#define CONFIG_TEST_BIT 0

#define S_IFMT 0
#define S_IFREG 0

void report_config_error(int, const char *, ...);
void free_list_element(list *, void *);
#define LIST_TAIL_DATA(list) NULL
#define __test_bit(bit, addr) false