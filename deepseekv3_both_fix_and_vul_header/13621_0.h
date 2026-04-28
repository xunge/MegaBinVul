#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *filename;

#ifdef OS_WINDOWS
char *ec_win_get_user_dir(void);
#endif

char *g_build_filename(const char *first, ...);
const char *g_get_tmp_dir(void);
void gtkui_conf_set(char *name, short value);
void DEBUG_MSG(const char *format, ...);