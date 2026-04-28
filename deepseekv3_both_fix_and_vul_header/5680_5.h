#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdint.h>

struct font_reader {
    void (*output_ascii)(const char *, int);
    void (*output_binary)(const char *, int);
    void (*output_end)(void);
};

typedef struct Clp_Parser {
    const char *vstr;
    /* other members omitted */
} Clp_Parser;

typedef struct Clp_Option {
    int id;
    const char *name;
    int type;
    /* other members omitted */
} Clp_Option;

enum {
    RAW_OPT = 1,
    MACBINARY_OPT,
    APPLESINGLE_OPT,
    APPLEDOUBLE_OPT,
    BINHEX_OPT,
    OUTPUT_OPT,
    FILENAME_OPT,
    HELP_OPT,
    VERSION_OPT,
    Clp_NotOption,
    Clp_Done,
    Clp_BadOption
};

static const Clp_Option options[] = {
    {RAW_OPT, "raw", 0},
    {MACBINARY_OPT, "macbinary", 0},
    {APPLESINGLE_OPT, "applesingle", 0},
    {APPLEDOUBLE_OPT, "appledouble", 0},
    {BINHEX_OPT, "binhex", 0},
    {OUTPUT_OPT, "output", 0},
    {FILENAME_OPT, "filename", 0},
    {HELP_OPT, "help", 0},
    {VERSION_OPT, "version", 0}
};

extern Clp_Parser *Clp_NewParser(int argc, const char *const *argv, int nopt, const Clp_Option *options);
extern int Clp_Next(Clp_Parser *clp);
extern const char *Clp_ProgramName(Clp_Parser *clp);

extern void fatal_error(const char *format, ...);
extern void error(const char *format, ...);
extern void usage(void);
extern void short_usage(void);

extern const char *program_name;
extern const char *VERSION;
extern FILE *rfork_f;
extern int nrsrc;
extern char *font_name;

#define PFB_MARKER 0x80
#define RFORK_HEADERLEN 16

extern void t1mac_output_ascii(const char *, int);
extern void t1mac_output_binary(const char *, int);
extern void t1mac_output_end(void);
extern void process_pfb(FILE *, const char *, struct font_reader *);
extern void process_pfa(FILE *, const char *, struct font_reader *);
extern void init_current_post(void);
extern void output_new_rsrc(const char *, int, int, const char *, int);
extern uint32_t complete_rfork(void);
extern void output_macbinary(FILE *, uint32_t, const char *, FILE *);
extern void output_raw(FILE *, uint32_t, FILE *);
extern void output_applesingle(FILE *, uint32_t, const char *, FILE *, int);
extern void output_binhex(FILE *, uint32_t, const char *, FILE *);

extern const unsigned char icon_bw_data[];
extern const unsigned char icon_8_data[];
extern const unsigned char icon_4_data[];
extern const unsigned char small_icon_bw_data[];
extern const unsigned char small_icon_8_data[];
extern const unsigned char small_icon_4_data[];