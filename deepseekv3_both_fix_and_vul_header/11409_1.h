#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef unsigned int uint;
typedef unsigned char byte;

typedef struct ref {
    byte *bytes;
    uint size;
    int type;
    struct { byte *bytes; } value;
} ref;

typedef struct gx_io_device gx_io_device;
typedef struct i_ctx_t {
    ref userparams;
} i_ctx_t;

typedef struct string_match_params {
    char wildcard;
    char single_char;
    char path_sep;
    bool ignore_case;
    bool path_sep_equiv;
} string_match_params;

extern void *imemory;
extern int gs_error_invalidfileaccess;
extern int t_string;

extern gx_io_device *iodev_default(void *);
extern int dict_find_string(ref *, const char *, ref **);
extern int array_get(void *, ref *, long, ref *);
extern uint gp_file_name_parents(const char *, int);
extern int gp_file_name_cwds(const char *, int);
extern bool gp_file_name_is_absolute(const char *, int);
extern int gs_file_name_check_separator(const char *, int, const char *);
extern bool string_match(const byte *, uint, const byte *, uint, const string_match_params *);
extern uint r_size(const ref *);
extern int r_type(const ref *);