#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef bool gboolean;
typedef char gchar;

#define FALSE false
#define TRUE true

extern char *FILENAME_TYPE;
extern bool is_correct_filename(char *);
extern void error_msg(const char *, ...);