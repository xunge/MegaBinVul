#include <stdint.h>

struct pdf_struct {
    uint32_t flags;
};

struct pdf_obj {
    uint32_t id;
};

enum pdf_flag {
    UNTERMINATED_OBJ_DICT,
    ESCAPED_COMMON_PDFNAME,
    BAD_STREAM_FILTERS,
    BAD_PDF_VERSION,
    BAD_PDF_HEADERPOS,
    BAD_PDF_TRAILER,
    BAD_PDF_TOOMANYOBJS,
    BAD_FLATE,
    BAD_FLATESTART,
    BAD_STREAMSTART,
    UNKNOWN_FILTER,
    BAD_ASCIIDECODE,
    HEX_JAVASCRIPT,
    BAD_INDOBJ,
    HAS_OPENACTION,
    HAS_LAUNCHACTION,
    BAD_STREAMLEN,
    ENCRYPTED_PDF,
    LINEARIZED_PDF,
    MANY_FILTERS,
    DECRYPTABLE_PDF
};

extern int cli_debug_flag;
extern void cli_dbgmsg(const char *format, ...);