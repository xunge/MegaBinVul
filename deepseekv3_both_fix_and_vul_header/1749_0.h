#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define JAS_OPT_HASARG 1
#define OPTSMAX 1024

typedef struct {
    int hasarg;
    const char *name;
    int id;
} jas_opt_t;

typedef struct {
    const char *infile;
    int infmt;
    const char *infmt_str;
    const char *inopts;
    char inoptsbuf[OPTSMAX];
    const char *outfile;
    int outfmt;
    const char *outfmt_str;
    const char *outopts;
    char outoptsbuf[OPTSMAX];
    int verbose;
    int version;
    int cmptno;
    int debug;
    int srgb;
    int list_codecs;
    int list_codecs_all;
    int help;
    uint64_t max_mem;
    const char *enable_format;
    int enable_all_formats;
} cmdopts_t;

extern int jas_getopt(int argc, char **argv, const jas_opt_t *opts);
extern char *jas_optarg;
extern int jas_optind;
extern uint64_t get_default_max_mem_usage(void);
extern void badusage(void);
extern void addopt(char *buf, size_t bufsize, const char *opt);