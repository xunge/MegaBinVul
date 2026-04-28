#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R_API
#define eprintf printf

typedef struct {
    char *data;
} RLineBuffer;

typedef struct {
    RLineBuffer buffer;
    char *contents;
    void *hist_up;
    void *hist_down;
} RLine;

typedef struct {
    RLine *line;
    char *(*cb_editor)(void *, const char *, const char *);
    void *user;
} RCons;

static RCons *I;
static char *path;
static char *lines;
static int bytes;
static int nlines;
static int _n;
static char prompt[32];
static void *up;
static void *down;

char *r_file_slurp(const char *file, int *bytes);
int r_str_split(char *str, char delimiter);
void r_line_set_prompt(const char *prompt);
char *r_line_readline(void);
void setnewline(int n);
void saveline(int n, const char *line);
void filesave(void);