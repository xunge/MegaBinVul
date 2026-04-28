#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>

enum objstate {
    STATE_NONE,
    STATE_LINEARIZED,
    STATE_LAUNCHACTION,
    STATE_JAVASCRIPT,
    STATE_OPENACTION,
    STATE_FILTER
};

enum pdf_objflags {
    OBJ_DICT,
    LINEARIZED_PDF,
    HAS_LAUNCHACTION,
    HAS_OPENACTION,
    OBJ_JAVASCRIPT,
    OBJ_OPENACTION,
    BAD_INDOBJ,
    MANY_FILTERS,
    OBJ_SIGNED,
    OBJ_FILTER_CRYPT,
    OBJ_FILTER_STANDARD,
    OBJ_FILTER_UNKNOWN,
    UNKNOWN_FILTER,
    KNOWN_FILTERS
};

struct pdf_struct {
    const char *map;
    size_t size;
    const char *fileID;
};

struct pdf_obj {
    size_t start;  // Changed to size_t for offset
    uint32_t id;
    uint32_t flags;
};

struct pdfname_action {
    enum pdf_objflags set_objflag;
    enum objstate from_state;
    enum objstate to_state;
};

static off_t obj_size(struct pdf_struct *pdf, struct pdf_obj *obj, int flag);
static const char *pdf_nextobject(const char *q, off_t bytesleft);
static int cli_hex2str_to(const char *q, char *out, int len);
static void handle_pdfname(struct pdf_struct *pdf, struct pdf_obj *obj, char *name, int escapes, enum objstate *state);
static void pdfobj_flag(struct pdf_struct *pdf, struct pdf_obj *obj, enum pdf_objflags flag);
static void pdf_parse_trailer(struct pdf_struct *pdf, const char *q, off_t len);
static long pdf_readint(const char *q, off_t len, const char *key);
static struct pdf_obj *find_obj(struct pdf_struct *pdf, struct pdf_obj *obj, uint32_t objid);
static void cli_dbgmsg(const char *fmt, ...);

struct pdfname_action pdfname_actions[] = {
    {OBJ_FILTER_CRYPT, STATE_FILTER, STATE_FILTER},
    {OBJ_FILTER_STANDARD, STATE_FILTER, STATE_FILTER}
};
#define PDFNAME_ACTIONS_SIZE (sizeof(pdfname_actions)/sizeof(pdfname_actions[0]))

static inline const char *pdf_get_ptr(const struct pdf_struct *pdf, size_t offset) {
    return pdf->map + offset;
}