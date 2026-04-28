#include <stdbool.h>
#include <stdint.h>

#define override 

#define HHVM_RC_BOOL_SAME(name)
#define HHVM_RC_BOOL(name, value)
#define HHVM_RC_INT_SAME(name) 
#define HHVM_RC_INT(name, value)
#define HHVM_FE(name)
#define HHVM_FALIAS(name1, name2)

bool one_bit_refcount;
int k_FB_SERIALIZE_HACK_ARRAYS;
int k_FB_SERIALIZE_VARRAY_DARRAY; 
int k_FB_SERIALIZE_HACK_ARRAYS_AND_KEYSETS;

void loadSystemlib();