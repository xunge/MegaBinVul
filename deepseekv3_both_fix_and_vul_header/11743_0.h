#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct argv_array {
    char **argv;
};

struct child_process {
    const char **argv;
    int git_cmd;
    int use_shell;
};

#define SHELL_PATH "/bin/sh"

static void die(const char *err, ...);
static void argv_array_push(struct argv_array *array, const char *string);
static void argv_array_pushv(struct argv_array *array, const char **argv);
static void prepare_shell_cmd(struct argv_array *out, const char **argv);
static char *locate_in_PATH(const char *file);
static void argv_array_clear(struct argv_array *array);