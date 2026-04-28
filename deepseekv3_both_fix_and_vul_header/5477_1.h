#include <stdlib.h>
#include <string.h>

typedef int bool_t;
#define FALSE 0
#define TRUE 1

typedef struct XDR {
    int x_op;
} XDR;
#define XDR_FREE 0
#define XDR_ENCODE 1
#define XDR_DECODE 2

typedef int krb5_int16;

typedef struct krb5_tl_data {
    krb5_int16 tl_data_type;
    unsigned int tl_data_length;
    char *tl_data_contents;
    struct krb5_tl_data *tl_data_next;
} krb5_tl_data;

bool_t xdr_bool(XDR *xdrs, bool_t *bp);
bool_t xdr_bytes(XDR *xdrs, char **cpp, unsigned int *sizep, unsigned int maxsize);
bool_t xdr_krb5_int16(XDR *xdrs, krb5_int16 *ip);