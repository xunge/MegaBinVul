#include <string.h>
#include <stdint.h>

#define CAMLprim
#define Long_val(x) ((intptr_t)(x))
#define Int_val(x) ((int)(x))
#define Byte(s, i) (((char *)(s))[i])
#define Val_unit ((value)0)
typedef intptr_t value;