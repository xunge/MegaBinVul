#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef bool bool_t;
typedef unsigned int u_int;

typedef struct XDR {
    int x_op;
} XDR;

#define XDR_ENCODE 0
#define XDR_DECODE 1
#define XDR_FREE 2

#define FALSE false
#define TRUE true

void *mem_alloc(size_t size);
void mem_free(void *ptr, size_t size);

bool_t xdr_u_int(XDR *xdrs, u_int *ip);
bool_t xdr_opaque(XDR *xdrs, char *cp, u_int cnt);