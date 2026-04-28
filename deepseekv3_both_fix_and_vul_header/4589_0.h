#include <stddef.h>
#include <sys/types.h>

typedef unsigned long ulong;

#define PHPAPI
#define TSRMLS_DC
#define TSRMLS_CC
#define DBG_ENTER(x)
#define DBG_RETURN(x)

struct mysqlnd_charset;
extern struct mysqlnd_charset * mysqlnd_find_charset_name(const char *name);
extern ulong mysqlnd_cset_escape_slashes(struct mysqlnd_charset *charset, char *newstr, const char *escapestr, size_t escapestr_len TSRMLS_DC);