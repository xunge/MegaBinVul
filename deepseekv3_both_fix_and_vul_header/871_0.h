#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void send_error(int code);
void build_needs_escape(void);
void index_directory(const char *dir1, const char *dir2);

#define USE_LOCALTIME
#define TIMEZONE(tm) (tm)->tm_zone