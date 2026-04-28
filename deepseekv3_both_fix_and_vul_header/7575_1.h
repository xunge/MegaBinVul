#include <stddef.h>

typedef struct mrb_state mrb_state;
typedef unsigned int mrb_sym;
typedef struct mt_tbl mt_tbl;

struct RClass {
  mt_tbl *mt;
};

int mt_del(mrb_state *mrb, mt_tbl *h, mrb_sym mid);
void mrb_name_error(mrb_state *mrb, mrb_sym mid, const char *fmt, ...);

#define MRB_API
#define MRB_CLASS_ORIGIN(c)