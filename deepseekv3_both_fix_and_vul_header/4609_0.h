#include <string.h>
#include <strings.h>

#define PHP_WIN32 0
#define FAILURE -1
#define SUCCESS 0
#define TSRMLS_DC
#define TSRMLS_CC

char *estrndup(const char *s, size_t length);
void phar_unixify_path_separators(char *filename, int filename_len);
int phar_detect_phar_fname_ext(char *filename, int filename_len, const char **ext_str, int *ext_len, int executable, int for_create, int dummy TSRMLS_DC);
char *phar_fix_filepath(char *entry, int *entry_len, int dummy TSRMLS_DC);
void efree(void *ptr);