#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

static int init_done;
static FILE *logfile;
static char *big_buffer;

enum output_type_enum {
    OUTPUT_FILE,
    OUTPUT_SYSLOG
};
static enum output_type_enum output_type;

struct coll_t {
    // define coll_t structure members as needed
};
static struct coll_t incl_user_coll;
static struct coll_t excl_user_coll;

static void *lock_operations;
static void *lock_atomic;
static void *lock_bigbuffer;

void coll_free(struct coll_t *coll);
void logger_close(FILE *logfile);
void flogger_mutex_destroy(void *mutex);
void error_header(void);