#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct {
    FILE *debug_file;
    unsigned int max_devs;
    int debug;
    int interactive;
    int cue;
    int nodetect;
    int manual;
    int nouserok;
    int openasuser;
    int alwaysok;
    int is_custom_debug_file;
    const char *auth_file;
    const char *authpending_file;
    const char *origin;
    const char *appid;
    const char *prompt;
} cfg_t;

#define D(debug_file, ...) do { \
    if (debug_file != (FILE *)-1) { \
        fprintf(debug_file, __VA_ARGS__); \
        fprintf(debug_file, "\n"); \
        fflush(debug_file); \
    } \
} while (0)