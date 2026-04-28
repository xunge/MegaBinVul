#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jas_stream_s jas_stream_t;
typedef struct jas_image_s jas_image_t;

extern int jas_init(void);
extern int jas_getopt(int argc, char **argv, const char *opts);
extern char *jas_optarg;
extern void jas_setdbglevel(int debug);
extern jas_stream_t *jas_stream_fopen(const char *filename, const char *mode);
extern jas_stream_t *jas_stream_fdopen(int fd, const char *mode);
extern int jas_stream_close(jas_stream_t *stream);
extern int jas_image_getfmt(jas_stream_t *in);
extern jas_image_t *jas_image_decode(jas_stream_t *in, int fmt, const char *optstr);
extern int jas_image_numcmpts(jas_image_t *image);
extern int jas_image_cmptwidth(jas_image_t *image, int cmptno);
extern int jas_image_cmptheight(jas_image_t *image, int cmptno);
extern int jas_image_cmptprec(jas_image_t *image, int cmptno);
extern char *jas_image_fmttostr(int fmt);
extern long jas_image_rawsize(jas_image_t *image);
extern void jas_image_destroy(jas_image_t *image);
extern void jas_image_clearfmts(void);

#define JAS_VERSION "unknown"
#define OPT_VERBOSE 0
#define OPT_VERSION 1
#define OPT_DEBUG 2
#define OPT_INFILE 3
#define OPT_HELP 4

static const char *opts = "vVd:i:h";
static char *cmdname;

void usage(void);