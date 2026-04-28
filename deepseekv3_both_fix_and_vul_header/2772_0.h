#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef int (*config_fn_t)(const char *, const char *, void *);

extern const char *config_exclusive_filename;
extern int perf_config_system(void);
extern int perf_config_global(void);
extern const char *perf_etc_perfconfig(void);
extern char *perf_pathdup(const char *);
extern int perf_config_from_file(config_fn_t fn, const char *filename, void *data);
extern char *mkpath(const char *fmt, ...);