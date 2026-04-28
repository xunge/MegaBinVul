#include <stdint.h>

#define DV_WIDE 0
#define DV_ANY 1
#define DV_STRING 2
#define DV_LONG_INT 3
#define DV_IRI_ID 4
#define DV_SINGLE_FLOAT 5
#define DV_DOUBLE_FLOAT 6
#define DV_NUMERIC 7
#define DV_DATETIME 8
#define DV_DATE 9
#define DV_TIMESTAMP 10
#define DV_TIME 11

typedef struct {
    int sqt_dtp;
} sqt_t;

typedef struct {
    sqt_t col_sqt;
} dbe_column_t;

typedef struct {
    int ssl_is_callret;
    int ssl_dc_dtp;
    sqt_t ssl_sqt;
} state_slot_t;

extern int dtp_canonical[];