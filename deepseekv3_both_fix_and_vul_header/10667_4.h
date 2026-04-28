#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct GHashTable GHashTable;
typedef struct {
    void *dummy1;
    void *dummy2;
    void *dummy3;
    int dummy4;
    int dummy5;
    void *dummy6;
} GHashTableIter;
typedef void* gpointer;
typedef char gchar;

extern int g_settings_nMaxCrashReportsSize;
extern char *g_settings_dump_location;
extern int g_settings_privatereports;
extern uid_t client_uid;
extern const char *VERSION;

#define DEFAULT_DUMP_DIR_MODE 0755
#define FILENAME_TYPE "FILENAME_TYPE"
#define FILENAME_CMDLINE "FILENAME_CMDLINE"
#define FILENAME_ABRT_VERSION "FILENAME_ABRT_VERSION"
#define FILENAME_UID "FILENAME_UID"

struct dump_dir;

gpointer g_hash_table_lookup(GHashTable *hash_table, const gchar *key);
void g_hash_table_remove(GHashTable *hash_table, const gchar *key);
void g_hash_table_iter_init(GHashTableIter *iter, GHashTable *hash_table);
int g_hash_table_iter_next(GHashTableIter *iter, gpointer *key, gpointer *value);
void g_hash_table_destroy(GHashTable *hash_table);

char *iso_date_string(time_t *time);
int low_free_space(unsigned long size, const char *path);
char *xasprintf(const char *format, ...);
void error_msg_and_die(const char *format, ...);
struct dump_dir *dd_create(const char *path, uid_t uid, mode_t mode);
void dd_create_basic_files(struct dump_dir *dd, uid_t client_uid, const char *executable);
void dd_save_text(struct dump_dir *dd, const char *name, const char *text);
void dd_close(struct dump_dir *dd);
char *get_cmdline(unsigned pid);
char *xstrndup(const char *str, size_t n);
void log_notice(const char *format, ...);
void trim_problem_dirs(const char *dir, double max_size, const char *exclude_path);
void run_post_create(const char *path);
int xdup2(int oldfd, int newfd);