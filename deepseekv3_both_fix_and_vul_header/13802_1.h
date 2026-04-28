#include <stdlib.h>
#include <stdbool.h>

#define R_API

typedef struct r_lang_plugin_t {
    int (*run_file)(void *lang, const char *file);
    int (*run)(void *lang, const char *code, int len);
} RLangPlugin;

typedef struct r_lang_t {
    RLangPlugin *cur;
} RLang;

char *r_file_slurp(const char *file, int *len);