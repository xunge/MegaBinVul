#include <stddef.h>

struct RClass {
  int tt;
  struct RClass *super;
};

#define MRB_TT_SCLASS 0
#define MRB_TT_ICLASS 0
#define MRB_API