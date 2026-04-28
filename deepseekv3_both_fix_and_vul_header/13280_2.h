#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <locale.h>
#include <libintl.h>
#include <unistd.h>

#define VERSION "unknown"
#define DBG_SUBDIR_CLIENT ""
#define CONFIG_INIT_CLIENT 0
#define CONFIG_INIT_GLOBAL 0
#define RUNNING_AS_CLIENT_LOGIN 0
#define RUNNING_AS_UID_ONLY 0
#define XFSDUMP "xfsdump"
#define VXDUMP "vxdump"
#define VDUMP "vdump"
#define DUMP "dump"
#define FALSE 0
#define _(x) x

typedef struct {
    char **pdata;
    unsigned int len;
    unsigned int alloc;
} GPtrArray;

typedef char gchar;

GPtrArray* g_ptr_array_new();
void g_ptr_array_add(GPtrArray *array, void *data);
void* g_ptr_array_free(GPtrArray *array, int free_segment);
char* g_strdup(const char *str);
char* g_strjoinv(const char *separator, char **str_array);
void g_strfreev(char **str_array);
int g_str_equal(const char *str1, const char *str2);
int g_fprintf(FILE *stream, const char *format, ...);

void glib_init(void);
void safe_fd(int fd, int minfd);
void safe_cd(void);
void set_pname(const char *name);
void dbopen(const char *subdir);
void config_init(int flags, void *arg);
void error(const char *msg);
void dbprintf(const char *fmt, ...);
void dbclose(void);
void check_running_as(int flags);
int become_root(void);
void dbrename(const char *config, const char *subdir);
char *quote_string(char *str);
char **safe_env(void);
void free_env(char **env);
void amfree(void *ptr);
char *get_pname(void);