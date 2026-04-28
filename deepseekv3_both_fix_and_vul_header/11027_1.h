#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct READER {
    FILE *fhd;
    void *gcol;
    void *all;
    void *superblock;
    int recursive_counter;
};

struct MYSOFA_HRTF;

typedef struct MYSOFA_HRTF MYSOFA_HRTF;

int superblockRead(struct READER *reader, void *superblock);
MYSOFA_HRTF *getHrtf(struct READER *reader, int *err);
void superblockFree(struct READER *reader, void *superblock);
void gcolFree(void *gcol);
int fprintf(FILE *stream, const char *format, ...);

#define CMAKE_INSTALL_PREFIX ""
#define log(format, ...) fprintf(stderr, format, ##__VA_ARGS__)