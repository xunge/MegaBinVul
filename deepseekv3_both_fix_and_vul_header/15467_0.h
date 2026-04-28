#include <stddef.h>
#include <errno.h>

#define FALSE 0
#define TRUE 1

#define PR_STR_FL_PRESERVE_WHITESPACE (1 << 0)
#define PR_STR_FL_PRESERVE_COMMENTS (1 << 1)
#define PR_STR_FL_IGNORE_QUOTES (1 << 2)

#define PR_ISSPACE(c) (isspace((int)(c)))

extern void pr_signals_handle(void);