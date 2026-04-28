#include <stdint.h>

typedef intptr_t mrb_int;
typedef struct mrb_state mrb_state;

struct RString {
    mrb_int len;
    char *ptr;
};

union mrb_value_ {
    void *p;
    mrb_int i;
};

typedef union mrb_value_ mrb_value;

#define MRB_API
#define E_ARGUMENT_ERROR 0
#define RSTR_LEN(s) ((s)->len)
#define RSTR_SET_LEN(s, l) ((s)->len = (l))
#define RSTR_PTR(s) ((s)->ptr)

void mrb_raisef(mrb_state *mrb, int error, const char *fmt, ...);
void mrb_str_modify(mrb_state *mrb, struct RString *s);
void resize_capa(mrb_state *mrb, struct RString *s, mrb_int len);
struct RString *mrb_str_ptr(mrb_value str);