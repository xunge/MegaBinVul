#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define RALL 0
#define RGLOBAL 1
#define RSCREEN 2
#define RSCREENS 3

#define OPQUERY 0
#define OPLOAD 1
#define OPMERGE 2
#define OPOVERRIDE 3
#define OPSYMBOLS 4
#define OPREMOVE 5
#define OPEDIT 6

#define MAX_CMD_DEFINES 100
#define PATHETICCPP 1
#define HAVE_MKSTEMP 1
#define RetainPermanent 1

typedef int Bool;
#define True 1
#define False 0

typedef struct {
    int room;
    int used;
} String;

typedef struct {
    int room;
    int used;
} Entries;

typedef struct {
    int dummy;
} Buffer;

char *ProgramName;
char *filename;
char *editFile;
char *backup_suffix;
char *cpp_program;
char *cpp_locations[10];
char *cmd_defines[MAX_CMD_DEFINES];
int num_cmd_defines;
int oper;
Bool dont_execute;
Bool quiet;
Bool need_real_defines;
void *dpy;
String includes;
String defines;
int defines_base;
Entries newDB;
Buffer buffer;
char tmpname[256];
char tmpname2[256];
char tmpname3[256];

void addstring(String *s, const char *str);
int isabbreviation(const char *str, const char *abbr, int minlen);
void Syntax(void);
void fatal(const char *fmt, ...);
void *XOpenDisplay(const char *name);
char *XDisplayName(const char *name);
int ScreenCount(void *dpy);
void DoDisplayDefines(void *dpy, String *defines, const char *displayname);
void InitBuffer(Buffer *buf);
void Process(int screen, Bool screen_specific, Bool output);
int DefaultScreen(void *dpy);
void InitEntries(Entries *entries);
void GetEntriesString(Entries *entries, const char *str);
void ShuffleEntries(Entries *entries, Entries *dbs, int count);
void ReProcess(int screen, Bool screen_specific);
void XSetCloseDownMode(void *dpy, int mode);
void XCloseDisplay(void *dpy);