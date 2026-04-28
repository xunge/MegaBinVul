#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define VERSION ""
#define ERRMSG ""
#define DBG_SUBDIR_CLIENT ""
#define CONFIG_INIT_CLIENT 0
#define CONFIG_INIT_GLOBAL 0
#define RUNNING_AS_CLIENT_LOGIN 0
#define RUNNING_AS_UID_ONLY 0
#define XFSDUMP ""
#define VXDUMP ""
#define VDUMP ""
#define DUMP ""

typedef struct {
    void **pdata;
    unsigned int len;
    unsigned int alloc;
} GPtrArray;

typedef char gchar;

int g_str_equal(const char *str1, const char *str2);
GPtrArray* g_ptr_array_new(void);
void g_ptr_array_add(GPtrArray *array, void *data);
void* g_ptr_array_free(GPtrArray *array, int free_segment);
char* g_strdup(const char *str);
char* g_strjoinv(const char *separator, char **str_array);
void g_strfreev(char **str_array);
void g_free(void *data);
int g_fprintf(FILE *stream, const char *format, ...);

char* _(const char *msg);
void safe_fd(int fd, int mode);
void safe_cd(void);
void set_pname(const char *name);
void dbopen(const char *subdir);
void config_init(int flags, void *arg);
void error(const char *msg);
void dbprintf(const char *format, ...);
void dbclose(void);
int become_root(void);
char* get_pname(void);
void dbrename(const char *config, const char *subdir);
void validate_dump_option(int argc, char **argv);
void validate_xfsdump_options(int argc, char **argv);
char* quote_string(char *str);
char** safe_env(void);
void amfree(void *ptr);
char** free_env(char **env);
void check_running_as(int flags);