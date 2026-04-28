#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_DUMPED_DD_COUNT 100
#define DEFAULT_DUMP_DIR_MODE 0755
#define S_IROTH 00004
#define FILENAME_ABRT_VERSION "abrt_version"
#define FILENAME_ANALYZER "analyzer"
#define FILENAME_TYPE "type"
#define FILENAME_CMDLINE "cmdline"

typedef struct dump_dir dump_dir;
typedef struct GList GList;

extern char *debug_dumps_dir;
extern int world_readable_dump;
extern int g_settings_privatereports;
extern int throttle_dd_creation;
extern const char *VERSION;

extern char *xmalloc_fopen_fgetline_fclose(const char *filename);
extern char *xmalloc_open_read_close(const char *filename, const char *maxsize);
extern char *iso_date_string(const time_t *t);
extern void log_notice(const char *fmt, ...);
extern void log(const char *fmt, ...);
extern char *concat_path_file(const char *dir, const char *filename);
extern dump_dir *dd_create(const char *path, uid_t uid, mode_t mode);
extern void dd_create_basic_files(dump_dir *dd, uid_t uid, const char *executable);
extern void save_oops_data_in_dump_dir(dump_dir *dd, char *oops_data, char *proc_modules);
extern void dd_save_text(dump_dir *dd, const char *name, const char *value);
extern void dd_close(dump_dir *dd);
extern void notify_new_path(const char *path);