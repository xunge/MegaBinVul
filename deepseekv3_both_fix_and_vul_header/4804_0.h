#include <stddef.h>

#define CAMLprim
#define Int_val(x) ((int)(x))
#define Atom(x) ((value)(x))
#define mlsize_t size_t

typedef void* value;

extern value caml_alloc(mlsize_t, int);