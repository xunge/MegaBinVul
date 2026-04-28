#include <stdbool.h>
#include <stdlib.h>

typedef long long wgint;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define DEBUGP(x) 
#define number_to_static_string(x) ""
#define fd_read_line(fd) NULL
#define fd_read(fd, buf, size, timeout) -1
#define fd_errstr(fd) ""
#define xfree(ptr) free(ptr)