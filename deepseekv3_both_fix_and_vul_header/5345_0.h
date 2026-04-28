#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define local static
#define MALLOC malloc
#define REALLOC realloc
#define FREE free
#define RELEASE free
#define SET_BINARY_MODE(fd)

struct globals {
    char inf[1024];
    int ind;
    char *name;
    time_t mtime;
    int headis;
    int list;
    int decode;
    int force;
    int pipeout;
    int recurse;
    char *sufx;
    char *hname;
    int verbosity;
    int outd;
    char *outf;
    int keep;
    time_t stamp;
    unsigned long in_tot;
    unsigned long out_tot;
    int procs;
} g;

local void bail(const char *msg1, const char *msg2);
local void complain(const char *fmt, ...);
local int compressed_suffix(char *path);
local char *justname(char *path);
local void in_init(void);
local int get_header(int first);
local void infchk(void);
local void unlzw(void);
local void show_info(int method, int cont, unsigned long check, unsigned long extra);
local void list_info(void);
local void cat(void);
local void copymeta(char *from, char *to);
local void touch(char *path, time_t stamp);
#ifndef NOTHREAD
local void parallel_compress(void);
#endif
local void single_compress(int cont);