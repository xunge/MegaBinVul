#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define FLAG_SHOW_PROGRESS 0
#define FLAG_KEEP_FILES 0
#define FLAG_THRESHOLD 0
#define PROCESSORS 0
#define PAGE_SIZE 0
#define T_ZERO 0
#define unlikely(x) (x)

typedef struct rzip_control {
    FILE *msgout;
    FILE *msgerr;
    int flags;
    const char *suffix;
    int compression_level;
    long ramsize;
    int threads;
    int page_size;
    int nice_val;
    time_t secs;
    unsigned char salt[16];
    int encloops;
    char *tmpdir;
} rzip_control;

void register_outputfile(rzip_control *control, FILE *file);
long get_ram(rzip_control *control);
int nloops(time_t secs, unsigned char *salt1, unsigned char *salt2);
bool get_rand(rzip_control *control, unsigned char *buf, int len);
void fatal_return(const char *msg, bool ret);
void print_output(const char *msg);