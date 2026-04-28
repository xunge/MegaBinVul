#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define INPUT_BUFFER_SIZE 4096
#define MAX_MESSAGE_SIZE (1024 * 1024)
#define FILENAME_EXECUTABLE "executable"

typedef struct GHashTable GHashTable;

extern char *g_settings_dump_location;
extern uid_t client_uid;
extern unsigned total_bytes_read;

GHashTable *g_hash_table_new_full(unsigned (*hash_func)(const void *key),
                                 int (*key_equal_func)(const void *a, const void *b),
                                 void (*key_destroy_func)(void *key),
                                 void (*value_destroy_func)(void *value));
void g_hash_table_destroy(GHashTable *hash_table);
void *g_hash_table_lookup(GHashTable *hash_table, const void *key);
unsigned g_str_hash(const void *v);
int g_str_equal(const void *v1, const void *v2);

char *xrealloc(void *ptr, size_t size);
char *skip_non_whitespace(char *str);
int prefixcmp(const char *str, const char *prefix);
int delete_path(const char *path);
int run_post_create(const char *data);
void process_message(GHashTable *problem_info, char *message);
unsigned convert_pid(GHashTable *problem_info);
void die_if_data_is_missing(GHashTable *problem_info);
int check_recent_crash_file(const char *last_file, const char *executable);
void create_problem_dir(GHashTable *problem_info, unsigned pid);
char *concat_path_file(const char *path, const char *filename);
void error_msg_and_die(const char *fmt, ...);
void perror_msg_and_die(const char *fmt, ...);
void log_debug(const char *fmt, ...);
void log_warning(const char *fmt, ...);
void error_msg(const char *fmt, ...);