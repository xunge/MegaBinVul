#include <stdio.h>
#include <string.h>

#define INDEX_NAME_LENGTH 256
#define INDEX_NAME_SUFFIX ".idx"
#define CFS_WRITE 0x01
#define CFS_APPEND 0x02

typedef enum {
    DB_OK,
    DB_STORAGE_ERROR
} db_result_t;

typedef struct {
    char name[256];
} relation_t;

typedef struct {
    char name[256];
} attribute_t;

typedef struct {
    relation_t *rel;
    attribute_t *attr;
    char descriptor_file[256];
    int type;
} index_t;

struct index_record {
    char attribute_name[256];
    char file_name[256];
    int type;
};

int cfs_open(const char *filename, int flags);
int cfs_write(int fd, const void *buf, size_t count);
int cfs_close(int fd);
void merge_strings(char *dest, const char *src1, const char *src2);
#define PRINTF printf