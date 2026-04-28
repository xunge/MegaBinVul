#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct pdf_struct {
    uint32_t enc_objid;
    char *fileID;
    void *objs;
    char *map;
};

struct pdf_obj {
    uint32_t start;
};

static uint32_t obj_size(struct pdf_struct *pdf, struct pdf_obj *obj, int flag);
static struct pdf_obj *find_obj(struct pdf_struct *pdf, void *objs, uint32_t enc_objid);
static uint32_t pdf_readint(const char *q, uint32_t len, const char *key);
static int pdf_readbool(const char *q, uint32_t len, const char *key, int def);
static char *pdf_readstring(const char *q, uint32_t len, const char *key, uint32_t *n);
static void dbg_printhex(const char *msg, const char *buf, uint32_t len);
static void check_user_password(struct pdf_struct *pdf, uint32_t R, char *O, char *U, uint32_t P, uint32_t EM, uint32_t length, uint32_t oulen);
static void cli_dbgmsg(const char *format, ...);
static const char *cli_memstr(const char *haystack, uint32_t haystacklen, const char *needle, uint32_t needlelen);