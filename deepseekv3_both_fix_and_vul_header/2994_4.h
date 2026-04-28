#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <endian.h>
#include <stddef.h>
#include <alloca.h>
#include <assert.h>
#include <stdint.h>

#define TZDIR "/usr/share/zoneinfo"
#define TZDEFAULT "/etc/localtime"
#define TZ_MAGIC "TZif"
#define FSETLOCKING_BYCALLER 1

struct tzhead {
    char tzh_magic[4];
    char tzh_version[1];
    char tzh_reserved[15];
    char tzh_ttisgmtcnt[4];
    char tzh_ttisstdcnt[4];
    char tzh_leapcnt[4];
    char tzh_timecnt[4];
    char tzh_typecnt[4];
    char tzh_charcnt[4];
};

struct ttinfo {
    long int offset;
    unsigned char isdst;
    unsigned char idx;
    unsigned char isstd;
    unsigned char isgmt;
};

struct leap {
    time_t transition;
    long int change;
};

extern int __use_tzfile;
extern int __libc_enable_secure;
extern time_t *transitions;
extern char *tzspec;
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern dev_t tzfile_dev;
extern ino_t tzfile_ino;
extern time_t tzfile_mtime;
extern size_t num_transitions;
extern size_t num_types;
extern size_t num_leaps;
extern unsigned char *type_idxs;
extern struct ttinfo *types;
extern char *zone_names;
extern struct leap *leaps;
extern long int rule_stdoff;
extern long int rule_dstoff;

static size_t decode(const char *);
static time_t decode64(const char *);
static void *__mempcpy(void *, const void *, size_t);
static char *__tzstring(const char *);
static void compute_tzname_max(size_t);
static void __fsetlocking(FILE *, int);

/* Replace stat64 with stat */
#define stat64 stat
#define fstat64 fstat