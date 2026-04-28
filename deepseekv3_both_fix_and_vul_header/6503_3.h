#include <stdio.h>
#include <stdlib.h>

typedef struct bfd bfd;

typedef struct asymbol {
    unsigned long flags;
} asymbol;

struct disassemble_info {
    int (*fprintf_func)(void *stream, const char *format, ...);
    void *stream;
};

typedef enum { FALSE, TRUE } bfd_boolean;
#define BSF_SECTION_SYM (1 << 0)
#define BSF_SYNTHETIC (1 << 1)
#define DMGL_ANSI (1 << 0)
#define DMGL_PARAMS (1 << 1)

extern char *bfd_asymbol_name(asymbol *);
extern char *bfd_demangle(bfd *, const char *, int);
extern const char *bfd_get_symbol_version_string(bfd *, asymbol *, bfd_boolean *);
extern int bfd_is_und_section(void *);
extern void *bfd_get_section(asymbol *);

extern int do_demangle;