#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

typedef struct {
    const char *data;
    size_t len;
} cstr_s;

typedef struct {
    int unnamed_count;
    int unnamed_max;
    int pos;
    int argc;
    char const **argv;
    char const *description;
    char const **names;
} fio_cli_parser_data_s;

extern void *fio_values;
extern void fio_cli_hash_insert(void *hash, size_t hash_val, cstr_s key, const char *value, void *udata);
extern const char *fio_cli_get_line_type(fio_cli_parser_data_s *parser, const char *line);
extern long fio_atol(char **str);
extern void fio_cli_end(void);

enum {
    FIO_CLI_BOOL__TYPE_I = 1,
    FIO_CLI_INT__TYPE_I = 2,
    FIO_CLI_STRING__TYPE_I = 3,
    FIO_CLI_PRINT__TYPE_I = 4,
    FIO_CLI_PRINT_HEADER__TYPE_I = 5
};

#define FIO_CLI_HASH_VAL(n) (n.len)