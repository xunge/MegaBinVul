#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <libintl.h>

#define VERSION ""
#define DBG_SUBDIR_CLIENT ""
#define CONFIG_INIT_CLIENT 0
#define CONFIG_INIT_GLOBAL 0
#define WANT_SETUID_CLIENT
#define RUNNING_AS_CLIENT_LOGIN 0
#define RUNNING_AS_UID_ONLY 0
#define GNUTAR_PATH ""
#define GNUTAR "gnutar"
#define FALSE 0

typedef struct _GPtrArray GPtrArray;
typedef char gchar;

GPtrArray* g_ptr_array_new();
void g_ptr_array_add(GPtrArray* array, void* data);
void* g_ptr_array_free(GPtrArray* array, int free_segment);
char* g_strdup(const char* str);
char* g_strdup_printf(const char* format, ...);
char* g_strjoinv(const char* separator, gchar** str_array);
void g_strfreev(gchar** str_array);
int g_str_equal(const char* str1, const char* str2);
int g_str_has_prefix(const char* str, const char* prefix);
void g_fprintf(FILE* stream, const char* format, ...);
void* g_new0(size_t size, size_t n_bytes);
void g_free(void* ptr);

void glib_init();
void safe_fd(int fd, int mode);
void safe_cd();
void set_pname(const char* name);
void dbopen(const char* subdir);
void config_init(int flags, void* unused);
void error(const char* msg, ...);
void dbprintf(const char* format, ...);
void dbclose();
int become_root();
void check_running_as(int flags);
void dbrename(const char* config, const char* subdir);
int check_exec_for_suid(const char* env_var, const char* default_path, FILE* stream, char** realpath);
char* quote_string(const char* str);
void amfree(void* ptr);
char* dbfn();
void dbreopen(const char* dbf, const char* mode);
char** safe_env();
void free_env(char** env);
const char* get_pname();
const char* _(const char* msg);

#define g_new0(type, count) ((type*)g_new0(sizeof(type), (count)))