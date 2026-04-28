#include <stdio.h>
#include <string.h>

#define INDEX_NAME_LENGTH 256
#define INDEX_NAME_SUFFIX ".idx"
#define CFS_READ 0

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
    int type;
    char descriptor_file[256];
} index_t;

struct index_record {
    char attribute_name[256];
    int type;
    char file_name[256];
};

int cfs_open(const char *filename, int mode);
int cfs_read(int fd, void *buf, size_t count);
int cfs_close(int fd);
void merge_strings(char *dest, const char *src1, const char *src2);
#define PRINTF printf