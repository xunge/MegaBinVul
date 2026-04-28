#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define BLOCK_LEN_OPT 1
#define OUTPUT_OPT 2
#define PFB_OPT 3
#define PFA_OPT 4
#define HELP_OPT 5
#define VERSION_OPT 6
#define Clp_NotOption 7
#define Clp_Done 8
#define Clp_BadOption 9

typedef struct Clp_Parser {
    struct {
        int i;
        char *vstr;
    } val;
    char *vstr;
} Clp_Parser;

extern Clp_Parser *Clp_NewParser(int argc, const char *const *argv, int option_count, const void *options);
extern char *Clp_ProgramName(Clp_Parser *clp);
extern int Clp_Next(Clp_Parser *clp);
extern void fatal_error(const char *format, ...);
extern void usage(void);
extern void short_usage(void);
extern void error(const char *format, ...);
extern void init_pfb_writer(void *w, int blocklen, FILE *ofp);
extern void pfb_writer_end(void *w);
extern void t1utils_getline(void);
extern void eexec_start(const char *p);
extern void eexec_string(const char *line);
extern void eexec_end(void);
extern void parse_charstring(void);

extern const char *VERSION;
extern const void *options;
extern char *program_name;
extern int blocklen;
extern FILE *ofp;
extern int pfb;
extern FILE *ifp;
extern int lenIV;
extern char line[1024];
extern char cs_start[256];
extern int ever_active;
extern int active;
extern int start_charstring;
extern int in_eexec;
extern void *w;