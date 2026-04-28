#include <stddef.h>

#define CAMLprim
#define Int_val(x) ((int)(x))
#define Double_wosize (sizeof(double) / sizeof(value))
#define Atom(x) ((value)(x))
#define value size_t

typedef size_t mlsize_t;
extern value caml_alloc(mlsize_t, int);