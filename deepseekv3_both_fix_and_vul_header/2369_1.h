#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

typedef long long wgint;

struct ptimer;
struct opt {
    bool show_progress;
    const char *dir_prefix;
    wgint limit_rate;
    double read_timeout;
};

extern struct opt opt;

void *xmalloc(size_t size);
void xfree(void *ptr);
struct ptimer *ptimer_new();
double ptimer_read(struct ptimer *);
void ptimer_measure(struct ptimer *);
void ptimer_destroy(struct ptimer *);
void *progress_create(const char *, wgint, wgint);
bool progress_interactive_p(void *);
void progress_update(void *, wgint, double);
void progress_finish(void *, double);
int fd_read(int, char *, int, double);
char *fd_read_line(int);
int write_data(FILE *, FILE *, const char *, int, wgint *, wgint *);
void limit_bandwidth_reset(void);
void limit_bandwidth(int, struct ptimer *);

#define BUFSIZ 8192
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define rb_read_exactly (1 << 0)
#define rb_chunked_transfer_encoding (1 << 1)
#define rb_compressed_gzip (1 << 2)
#define rb_skip_startpos (1 << 3)