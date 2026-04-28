#include <stdio.h>
#include <string.h>
#include <strings.h>

#define FN_REFLEN 512
#define MY_FAE 0
#define MYF(flags) flags

extern char *opt_basedir;
extern char *opt_datadir;
extern char *opt_plugin_dir;

struct plugin_data {
    char name[FN_REFLEN];
};

extern struct plugin_data plugin_data;

char *my_strndup(const char *s, size_t n, int flags);
int load_plugin_data(const char *plugin_name, const char *config_file);