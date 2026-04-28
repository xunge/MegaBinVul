#include <stdint.h>
#include <sys/types.h>

typedef char *caddr_t;
typedef int64_t int64;
typedef long boxint;
typedef struct state_slot_t state_slot_t;

#define BOXINT_FMT "ld"
#define NEW_DB_NULL ((caddr_t)0)
#define sqlr_new_error(a, b, c, d, e)
#define bif_long_or_null_arg(a, b, c, d, e) 0
#define box_num(a) ((caddr_t)0)