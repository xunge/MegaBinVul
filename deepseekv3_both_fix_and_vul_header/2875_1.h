#include <pwd.h>
#include <shadow.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define UNUSED __attribute__((unused))
#define RLM_MODULE_NOOP 0
#define RLM_MODULE_NOTFOUND 1
#define RLM_MODULE_USERLOCK 2
#define RLM_MODULE_REJECT 3
#define RLM_MODULE_UPDATED 4
#define RLM_MODULE_FAIL 5
#define L_AUTH 0
#define T_OP_SET 0

typedef struct {
    char *vp_strvalue;
} VALUE_PAIR;

typedef struct {
    VALUE_PAIR *username;
    long timestamp;
} REQUEST;

VALUE_PAIR *pairmake(const char *name, const char *value, int op);
void pairmove(VALUE_PAIR **dst, VALUE_PAIR **src);
void pairfree(VALUE_PAIR **vp);
void radlog(int level, const char *fmt, ...);
void radlog_request(int level, int foo, REQUEST *request, const char *fmt, ...);