#include <stdint.h>
#include <string.h>

typedef struct xd3_stream xd3_stream;
typedef struct main_file main_file;

typedef unsigned long usize_t;

extern int option_use_appheader;

int xd3_get_appheader(xd3_stream *stream, uint8_t **apphead, usize_t *appheadsz);
void main_get_appheader_params(main_file *file, char **parsed, int is_output, const char *name, main_file *ifile);