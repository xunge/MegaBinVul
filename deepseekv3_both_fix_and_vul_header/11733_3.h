#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define EXIT_IF_NOT_FOUND 0
#define R_RESTART 1
#define R_COMMENT 2
#define USE_SA_FILE 0
#define UEOF_STOP 0
#define S_F_LOCAL_TIME 0
#define FALSE 0
#define TRUE 1
#define BITMAP_SIZE(x) ((x) * 8)

struct file_activity {
    int dummy;
};

struct file_magic {
    int dummy;
};

struct file_hdr {
    int sa_act_nr;
};

struct record_hdr {
    unsigned char record_type;
};

struct tm_start {
    void *use;
};

struct tm_end {
    void *use;
};

struct rectime {
    int dummy;
};

struct sar_fmt {
    int dummy;
};

struct bitmap {
    unsigned char *b_array;
    int b_size;
};

struct activity {
    struct bitmap *bitmap;
    int *nr;
};

extern struct activity **act;
extern unsigned int id_seq;
extern struct record_hdr record_hdr[2];
extern long count;
extern struct file_hdr file_hdr;
extern int dis;
extern int *flags;
extern struct tm_start tm_start;
extern struct tm_end tm_end;
extern struct rectime rectime;
extern struct sar_fmt sar_fmt;

void copy_structures(struct activity **act, unsigned int id_seq, struct record_hdr *record_hdr, int curr, int num);
int get_activity_position(struct activity **act, unsigned int act_id, int exit_if_not_found);
int count_bits(void *array, int size);
int read_record_hdr(int ifd, void *rec_hdr_tmp, struct record_hdr *record_hdr, struct file_hdr *file_hdr, int arch_64, int endian_mismatch, int ueof_stop, ...);
void read_file_stat_bunch(struct activity **act, int curr, int ifd, int sa_act_nr, struct file_activity *file_actlst, int endian_mismatch, int arch_64, char *file, struct file_magic *file_magic, int ueof_stop);
int print_special_record(struct record_hdr *record_hdr, int *flags, struct tm_start *tm_start, struct tm_end *tm_end, int r_comment, int ifd, struct rectime *rectime, void *null, char *file, int num, struct file_magic *file_magic, struct file_hdr *file_hdr, struct activity **act, struct sar_fmt *sar_fmt, int endian_mismatch, int arch_64);
int write_stats(int curr, int use_sa_file, long *cnt, void *use1, void *use2, int reset, unsigned int act_id, int reset_cd);
void write_stats_avg(int curr, int use_sa_file, unsigned int act_id);