#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *opt_basedir = NULL;
static char *opt_plugin_dir = NULL;
static char *opt_datadir = NULL;
static char *opt_plugin_ini = NULL;
static int opt_print_defaults = 0;
static int opt_no_defaults = 0;
static int opt_verbose = 0;

#define FN_LIBCHAR '/'
#define FN_LIBCHAR2 '\\'
#define FN_DIRSEP "/"
#define FN_REFLEN 512

#define MY_FAE 0
#define MYF(flags) flags

typedef struct {
    const char *name;
    int id;
    int arg_type;
    void *arg;
    const char *comment;
    int *app_type;
} my_option;

static my_option *my_long_options = NULL;

static int handle_options(int *argc, char ***argv, const my_option *options, int (*get_one_option)(int, const my_option *, char **)) {
    return 0;
}

static size_t strlength(const char *str) {
    return strlen(str);
}

static void *my_free(void *ptr) {
    free(ptr);
    return NULL;
}

static char *my_strdup(const char *str, int flags) {
    return strdup(str);
}

static int get_default_values(void) {
    return 0;
}

static int check_options(int argc, char *argv[], char *operation) {
    return 0;
}

static int get_one_option(int optid, const my_option *opt, char **argument) {
    return 0;
}