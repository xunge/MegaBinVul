#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef char *sds;

struct configStruct {
    int interactive;
    int eval;
    int eval_ldb;
    int eval_ldb_end;
    int eval_ldb_sync;
    int output;
    char *hostip;
    int hostport;
    char *prompt;
} config;

typedef struct linenoiseCompletions {
    size_t len;
    char **cvec;
} linenoiseCompletions;

#define REDIS_CLI_HISTFILE_ENV "REDISCLI_HISTFILE"
#define REDIS_CLI_HISTFILE_DEFAULT "/.rediscli_history"
#define OUTPUT_RAW 1

void linenoiseSetMultiLine(int ml);
void linenoiseSetCompletionCallback(void (*callback)(const char *, linenoiseCompletions *));
void linenoiseSetHintsCallback(char *(*callback)(const char *, int *color, int *bold));
void linenoiseSetFreeHintsCallback(void (*callback)(void *));
char *linenoise(const char *prompt);
void linenoiseHistoryAdd(const char *line);
int linenoiseHistoryLoad(const char *filename);
int linenoiseHistorySave(const char *filename);
void linenoiseFree(void *ptr);
void linenoiseClearScreen(void);

void completionCallback(const char *buf, linenoiseCompletions *lc);
char *hintsCallback(const char *buf, int *color, int *bold);
void freeHintsCallback(void *ptr);

sds getDotfilePath(const char *envvar, const char *default_path);
void cliLoadPreferences(void);
void cliRefreshPrompt(void);
sds *cliSplitArgs(char *line, int *argc);
void cliSetPreferences(sds *argv, int argc, int interactive);
void cliConnect(int force);
void cliReadReply(int output_raw);
void issueCommandRepeat(int argc, sds *argv, int repeat);
void sdsfreesplitres(sds *tokens, int count);
sds sdsnew(const char *init);
void sdsfree(sds s);

long long mstime(void);

void *context;