#include <stdlib.h>
#include <string.h>

typedef struct problem_data problem_data_t;
typedef struct dump_dir {
    char *dd_dirname;
} dump_dir;

extern int g_settings_privatereports;
extern char *g_settings_dump_location;

void load_abrt_conf(void);
struct dump_dir *create_dump_dir_from_problem_data_ext(problem_data_t *pd, char *location, int flags);
struct dump_dir *create_dump_dir_from_problem_data(problem_data_t *pd, char *location);
void dd_close(struct dump_dir *dd);
void log_info(const char *fmt, ...);
char *xstrdup(const char *s);