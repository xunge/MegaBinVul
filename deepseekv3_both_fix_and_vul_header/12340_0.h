#include <stdint.h>

typedef struct _bc_num {
  int n_scale;
} *bc_num;

typedef struct String {
  const char* data() const;
  String(const char*, int);
  String();
} String;

typedef struct Variant {
  Variant();
  Variant(const String&);
  Variant& operator=(const String&);
} Variant;

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)
#define BCG(x) (x)
#define SCOPE_EXIT for(;0;)
#define AttachString 0

extern int bc_precision;
extern void bc_init_num(bc_num* num);
extern void bc_free_num(bc_num* num);
extern void php_str2num(bc_num* num, char* str);
extern int bc_sqrt(bc_num* num, int64_t scale);
extern char* bc_num2str(bc_num num);
extern void raise_warning(const char* msg);

static inline int64_t adjust_scale(int64_t scale) {
  return scale < 0 ? BCG(bc_precision) : scale;
}