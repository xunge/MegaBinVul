#include <time.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdbool.h>

typedef int date;
typedef int fsec_t;

#define MAXDATEFIELDS 64
#define MAXDATELEN 128
#define PGTYPES_DATE_BAD_DATE 1
#define FALSE false

enum
{
    DTK_DATE,
    DTK_EPOCH
};

extern int ParseDateTime(char *str, char *lowstr, char **field, int *ftype, int *nf, char **ptr);
extern int DecodeDateTime(char **field, int *ftype, int nf, int *dtype, struct tm *tm, fsec_t *fsec, bool EuroDates);
extern int GetEpochTime(struct tm *tm);
extern int date2j(int year, int mon, int mday);