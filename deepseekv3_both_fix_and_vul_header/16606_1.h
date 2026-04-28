#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#define MAX_PATH 260
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

static const unsigned int delay[] = { 0, 1, 10, 100, 1000 };

static int xutftowcs_path(wchar_t *wcs, const char *utf);
static int is_file_in_use_error(unsigned long err);
static int err_win_to_posix(unsigned long winerr);
static int is_dir_empty(const wchar_t *wpathname);
static int ask_yes_no_if_possible(const char *format, ...);
static int _wrmdir(const wchar_t *wpathname);
static unsigned long GetLastError(void);
static void Sleep(unsigned long ms);