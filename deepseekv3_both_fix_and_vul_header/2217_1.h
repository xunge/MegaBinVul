#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct t_hook {
    int child_read[2];
    int child_write[2];
    char *command;
    char *options;
};

#define HOOK_PROCESS(hook, field) ((hook)->field)
#define HOOK_PROCESS_STDOUT 0
#define HOOK_PROCESS_STDERR 1

extern int weechat_debug_core;
extern char **string_split_shell(const char *string);
extern void string_free_split(char **split_string);
extern int weeurl_download(const char *url, const char *options);
extern void log_printf(const char *format, ...);