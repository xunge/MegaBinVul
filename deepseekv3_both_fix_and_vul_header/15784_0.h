#include <stdlib.h>
#include <string.h>

#define DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE (1 << 0)
#define FILENAME_OS_RELEASE "os-release"

struct dump_dir {
    const char *dd_dirname;
};

extern int str_is_correct_filename(const char *);
extern void error_msg(const char *fmt, ...);
extern void xfunc_die(void);
extern char *concat_path_file(const char *, const char *);
extern char *load_text_file(const char *, unsigned);