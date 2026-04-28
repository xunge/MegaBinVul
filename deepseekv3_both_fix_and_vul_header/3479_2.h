#include <time.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

typedef int64_t timestamp;
typedef int64_t int64;
typedef int fsec_t;

#define MAXDATEFIELDS 64
#define MAXDATELEN 128
#define PGTYPES_TS_BAD_TIMESTAMP (-1)

#define HAVE_INT64_TIMESTAMP 1

#define TIMESTAMP_NOEND(result) ((result) = INT64_MAX)
#define TIMESTAMP_NOBEGIN(result) ((result) = INT64_MIN)

enum {
    DTK_DATE,
    DTK_EPOCH,
    DTK_LATE,
    DTK_EARLY,
    DTK_INVALID
};

int ParseDateTime(char *str, char *lowstr, char **field, int *ftype, int *nf, char **ptr);
int DecodeDateTime(char **field, int *ftype, int nf, int *dtype, struct tm *tm, fsec_t *fsec, int flags);
int tm2timestamp(struct tm *tm, fsec_t fsec, int *tzp, timestamp *result);
timestamp SetEpochTimestamp(void);