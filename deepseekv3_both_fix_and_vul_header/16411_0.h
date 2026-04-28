#include <ctype.h>
#include <time.h>

#define SRS_TIME_BASECHARS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SRS_TIME_BASEBITS 5
#define SRS_TIME_PRECISION 3600
#define SRS_TIME_SLOTS (1 << (2 * SRS_TIME_BASEBITS))

#define SRS_SUCCESS 0
#define SRS_EBADTIMESTAMPCHAR -1
#define SRS_ETIMESTAMPOUTOFDATE -2

typedef struct {
    int maxage;
} srs_t;