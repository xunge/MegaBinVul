#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAXDATEFIELDS 64
#define MAXDATELEN 128
#define PGTYPES_INTVL_BAD_INTERVAL 1

typedef int fsec_t;

typedef struct interval {
    /* Define your interval structure members here */
    /* Example: */
    int days;
    int months;
    int years;
    int hours;
    int minutes;
    int seconds;
    int microseconds;
} interval;

enum {
    DTK_DELTA
};

extern int ParseDateTime(char *str, char *lowstr, char **field, int *ftype, int *nf, char **ptr);
extern int DecodeInterval(char **field, int *ftype, int nf, int *dtype, struct tm *tm, fsec_t *fsec);
extern int DecodeISO8601Interval(char *str, int *dtype, struct tm *tm, fsec_t *fsec);
extern int tm2interval(struct tm *tm, fsec_t fsec, interval *result);
extern void *pgtypes_alloc(size_t size);