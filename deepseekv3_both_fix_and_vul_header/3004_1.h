#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>

#define PATHSEP "/"
#define NAME_MAX 255
#define O_BINARY 0

#define CL_SUCCESS 0
#define CL_CLEAN 1
#define CL_ETMPFILE 2
#define CL_EMEM 3
#define CL_EWRITE 4
#define CL_EUNLINK 5
#define CL_VIRUS 6

#define OBJ_STREAM 0
#define OBJ_HASFILTERS 1
#define DUMP_MASK 0
#define OBJ_IMAGE 2
#define OBJ_FILTER_DCT 3
#define OBJ_FORCEDUMP 4
#define OBJ_FILTER_FLATE 5
#define OBJ_FILTER_AH 6
#define OBJ_FILTER_A85 7
#define OBJ_TRUNCATED 8
#define OBJ_JAVASCRIPT 9

#define BAD_STREAMLEN 0
#define BAD_ASCIIDECODE 1
#define HEX_JAVASCRIPT 2

#define PDF_PHASE_POSTDUMP 0

struct pdf_struct {
    char *map;
    off_t size;
    char *dir;
    unsigned int files;
    struct cl_ctx *ctx;
    struct pdf_obj *objs;
};

struct pdf_obj {
    unsigned int flags;
    unsigned int id;
    off_t start;
};

struct cl_engine {
    int keeptmp;
};

struct cl_ctx {
    struct cl_engine *engine;
};

void cli_dbgmsg(const char *format, ...);
void cli_errmsg(const char *format, ...);
char *cli_strerror(int errnum, char *buf, size_t buflen);
void *cli_malloc(size_t size);
void pdfobj_flag(struct pdf_struct *pdf, struct pdf_obj *obj, int flag);
off_t find_length(struct pdf_struct *pdf, struct pdf_obj *obj, const char *start, off_t p_stream);
void find_stream_bounds(const char *start, off_t size1, off_t size2, off_t *p_stream, off_t *p_endstream);
long asciihexdecode(const char *in, size_t inlen, char *out);
long ascii85decode(const char *in, size_t inlen, unsigned char *out);
off_t obj_size(struct pdf_struct *pdf, struct pdf_obj *obj, int arg);
const char *pdf_nextobject(const char *q, off_t bytesleft);
void cli_hex2str_to(const char *q2, char *decoded, int len);
int filter_flatedecode(struct pdf_struct *pdf, struct pdf_obj *obj, const char *in, long inlen, int fout, off_t *sum);
int filter_writen(struct pdf_struct *pdf, struct pdf_obj *obj, int fout, const char *in, off_t inlen, off_t *sum);
void cli_updatelimits(struct cl_ctx *ctx, off_t sum);
int cli_magic_scandesc(int fd, struct cl_ctx *ctx);
int run_pdf_hooks(struct pdf_struct *pdf, int phase, int fout, int objidx);
int cli_unlink(const char *path);
const char *cli_memstr(const char *haystack, size_t haystacklen, const char *needle, size_t needlelen);