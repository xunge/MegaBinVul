#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct language language;
typedef struct fdesc fdesc;
typedef struct compressor compressor;

struct fdesc {
    char *infname;
    fdesc *next;
};

struct compressor {
    char *suffix;
    char *command;
};

extern char *tagfile;
extern fdesc *fdhead;
extern fdesc *curfdp;
extern void *last_node;
extern compressor compressors[];
extern int MSDOS;

#define FOPEN_BINARY "b"
#define UNINIT

extern void canonicalize_filename(char *);
extern int streq(const char *, const char *);
extern void error(const char *, ...);
extern compressor *get_compressor_from_suffix(char *, char **);
extern char *savenstr(const char *, size_t);
extern char *concat(const char *, ...);
extern void *memmove(void *, const void *, size_t);
extern char *etags_mktmp(void);
extern int system(const char *);
extern void process_file(FILE *, char *, language *);
extern void pfatal(const char *);