#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>

#define E_NOTHANDLED -1
#define E_INVALID -2
#define E_SUCCESS 0

#define EC_FILTER_MAGIC 0x1234
#define EC_VERSION "1.0"
#define O_BINARY 0

struct filter_op {
    int dummy;
};

struct filter_header {
    u_short magic;
    char version[16];
    size_t data;
    size_t code;
};

struct global_options {
    char *output_file;
};

extern struct global_options *EF_GBL_OPTIONS;

#define ON_ERROR(cond, err, fmt, ...) \
    if ((cond) == (err)) { \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        return -1; \
    }

size_t compile_tree(struct filter_op **fop);
u_char *create_data_segment(struct filter_header *fh, struct filter_op *fop, size_t ninst);
void print_progress_bar(struct filter_op *fop);