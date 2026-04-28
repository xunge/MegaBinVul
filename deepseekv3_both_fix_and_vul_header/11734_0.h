#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_RECORD_HEADER_SIZE 1024
#define MAX_COMMENT_LEN 1024
#define R_COMMENT 1
#define R_RESTART 2
#define IGNORE_COMMENT 1
#define IGNORE_RESTART 2
#define SET_TIMESTAMPS 4
#define DONT_READ_CPU_NR 8
#define UEOF_CONT 1
#define TRUE 1

struct file_magic;
struct file_activity;
struct record_hdr {
    int record_type;
};
struct file_hdr {
    int sa_cpu_nr;
    int sa_act_nr;
};

extern struct record_hdr record_hdr[];
extern struct file_hdr file_hdr;
extern int flags;
extern int arch_64;
extern int endian_mismatch;
extern struct tm tm_start;
extern struct tm tm_end;
extern int act;
extern int f_position;
extern void *fmt[];