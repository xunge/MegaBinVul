#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Eventinfo {
    char *location;
    char *full_log;
    char *log;
    char *hostname;
    char *program_name;
    size_t p_name_size;
    int day;
    int year;
    char mon[4];
    char hour[9];
    time_t time;
} Eventinfo;

extern char *__shost;
extern time_t c_time;
extern int __crt_hour;
extern int __crt_wday;
extern char *ARGV0;
extern int alert_only;

#define FORMAT_ERROR "Invalid message format"
#define os_strdup(src, dst) (dst = strdup(src))
#define os_malloc(size, ptr) (ptr = malloc(size))
#define merror(msg, arg) fprintf(stderr, msg, arg)

static inline int isValidChar(char c) {
    return isalnum(c) || c == '_' || c == '-' || c == '.' || c == '/';
}

static const char *month[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

#ifdef TESTRULE
void print_out(const char *format, ...);
#endif