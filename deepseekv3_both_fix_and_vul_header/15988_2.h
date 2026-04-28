#include <stdbool.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef struct oparg_S {
} oparg_T;

bool text_locked(void);
void clearopbeep(oparg_T *oap);
void text_locked_msg(void);