#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXALIASLEN 255
#define ALIASES_FILE "aliases.txt"
#define MSG_ALIASES_BROKEN_FILE "Broken aliases file"
#define LOG_ERR 1

typedef struct DirAlias {
    char *alias;
    char *dir;
    struct DirAlias *next;
} DirAlias;

extern DirAlias *head;
extern DirAlias *tail;
extern int aliases_up;

void die_mem(void);
void logfile(int level, const char *message);