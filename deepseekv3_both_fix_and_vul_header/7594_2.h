#include <stdbool.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <libgen.h>
#include <getopt.h>

extern int optind;
extern char *optarg;

typedef struct rzip_control {
    int flags;
    char *passphrase;
    char *outname;
    char *outdir;
    const char *suffix;
    long ramsize;
    int nice_val;
    int compression_level;
    int threads;
    int window;
    FILE *msgout;
    FILE *outFILE;
    FILE *inFILE;
    char *infile;
    int current_priority;
} rzip_control;

struct rzip_control base_control;
struct rzip_control *control;
struct rzip_control local_control;

#define FLAG_DECOMPRESS 0x01
#define FLAG_STDOUT 0x02
#define FLAG_SHOW_PROGRESS 0x04
#define FLAG_KEEP_FILES 0x08
#define FLAG_BZIP2_COMPRESS 0x10
#define FLAG_ZLIB_COMPRESS 0x20
#define FLAG_LZO_COMPRESS 0x40
#define FLAG_NO_COMPRESS 0x80
#define FLAG_ZPAQ_COMPRESS 0x100
#define FLAG_NOT_LZMA 0x200
#define FLAG_CHECK 0x400
#define FLAG_HASH 0x800
#define FLAG_FORCE_REPLACE 0x1000
#define FLAG_INFO 0x2000
#define FLAG_KEEP_BROKEN 0x4000
#define FLAG_TEST_ONLY 0x8000
#define FLAG_THRESHOLD 0x10000
#define FLAG_UNLIMITED 0x20000
#define FLAG_VERBOSITY 0x40000
#define FLAG_VERBOSITY_MAX 0x80000
#define FLAG_STDIN 0x100000
#define FLAG_ENCRYPT 0x200000

#define PRIO_MIN -20
#define MAX_PATH_LEN 4096

#define unlikely(x) (x)
#define likely(x) (x)

#define STDOUT (control->flags & FLAG_STDOUT)
#define STDIN (control->flags & FLAG_STDIN)
#define DECOMPRESS (control->flags & FLAG_DECOMPRESS)
#define NO_COMPRESS (control->flags & FLAG_NO_COMPRESS)
#define VERBOSE (control->flags & FLAG_VERBOSITY)
#define SHOW_PROGRESS (control->flags & FLAG_SHOW_PROGRESS)
#define KEEP_FILES (control->flags & FLAG_KEEP_FILES)
#define FORCE_REPLACE (control->flags & FLAG_FORCE_REPLACE)
#define TEST_ONLY (control->flags & FLAG_TEST_ONLY)
#define CHECK_FILE (control->flags & FLAG_CHECK)
#define INFO (control->flags & FLAG_INFO)
#define ENCRYPT (control->flags & FLAG_ENCRYPT)
#define UNLIMITED (control->flags & FLAG_UNLIMITED)

#define PACKAGE_VERSION "unknown"

static struct option long_options[] = {
    {"help", 0, 0, 'h'},
    {"version", 0, 0, 'V'},
    {"stdout", 0, 0, 'c'},
    {"keep", 0, 0, 'k'},
    {0, 0, 0, 0}
};

static const char *coptions = "b:g:l:n:z:/cCdDe:fHhIiKkL:m:N:o:O:p:PqS:tTUvVw:123456789";
static const char *loptions = "b:g:l:n:z:/cCdDe:fHhIiKkL:m:N:o:O:p:PqS:tTUvVw:123456789";

void initialise_control(struct rzip_control *control);
void CrcGenerateTable(void);
bool read_config(struct rzip_control *control);
void failure(const char *fmt, ...);
void fatal(const char *fmt, ...);
void usage(bool compat);
void license(void);
void set_stdout(struct rzip_control *control);
void print_output(const char *fmt, ...);
void print_err(const char *fmt, ...);
void setup_overhead(struct rzip_control *control);
void recurse_dirlist(char *infile, char **dirlist, int *direntries);
void register_outputfile(struct rzip_control *control, FILE *msgout);
void sighandler(int sig);
void setup_ram(struct rzip_control *control);
void show_summary(void);
void print_progress(const char *fmt, ...);
void decompress_file(struct rzip_control *control);
void get_fileinfo(struct rzip_control *control);
void compress_file(struct rzip_control *control);