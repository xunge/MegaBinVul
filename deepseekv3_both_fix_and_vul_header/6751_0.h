#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define RC_DIR ""
#define CONFIG_FILE ""
#define W3MCONFIG ""
#define FALSE 0
#define TRUE 1
#define USE_M17N

extern char *rc_dir;
extern char *config_file;
extern char *tmp_dir;
extern int no_rc_dir;
extern char *display_charset_str;
extern char *document_charset_str;
extern char *system_charset_str;

char *expandPath(const char *path);
char *rcFile(const char *file);
char *etcFile(const char *file);
char *confFile(const char *file);
int do_mkdir(const char *path, mode_t mode);
void interpret_rc(FILE *f);
void create_option_search_table();

#ifdef USE_M17N
char *wc_get_ces_list(void);
#endif