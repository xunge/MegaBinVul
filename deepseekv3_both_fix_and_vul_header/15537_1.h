#include <stdint.h>

typedef unsigned long VALUE;
typedef unsigned int ID;
#define T_HASH 0
#define Qnil 0
#define Qundef 0
#define RB_TYPE_P(obj, type) 0
#define rb_intern2(name, len) 0
#define rb_respond_to(obj, id) 0
#define ID2SYM(id) 0
#define rb_hash_lookup2(hash, key, def) 0
#define rb_sym2str(sym) 0

typedef struct {
    VALUE (*call)(VALUE, ID);
} IodineCaller_t;
static IodineCaller_t IodineCaller;