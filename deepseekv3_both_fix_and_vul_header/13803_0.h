#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ut8;

char *r_str_newf(const char *fmt, ...);
char *r_file_slurp(const char *file, int *sz);
char *r_str_replace(char *str, const char *key, const char *val, bool g);
void r_str_stripLine(char *str, const char *key);
bool r_file_dump(const char *file, const ut8 *buf, int len, bool append);
void eprintf(const char *fmt, ...);