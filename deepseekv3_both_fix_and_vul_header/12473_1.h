#include <stdbool.h>
#include <string.h>

struct scanner;
struct environment;
struct evalstring;

struct rule {
    char *name;
    /* other members assumed by ruleaddvar() */
};

struct rule *mkrule(char *name);
void scannewline(struct scanner *s);
bool scanindent(struct scanner *s);
char *scanname(struct scanner *s);
void parselet(struct scanner *s, struct evalstring **val);
void ruleaddvar(struct rule *r, char *var, struct evalstring *val);
void fatal(const char *fmt, ...);
void envaddrule(struct environment *env, struct rule *r);