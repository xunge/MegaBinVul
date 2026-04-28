#include <stdbool.h>
#include <string.h>
#include <stddef.h>

struct string {
    size_t n;
};

struct edge {
    struct pathlist *in;
    struct pathlist *out;
    size_t inimpidx;
    size_t outimpidx;
    struct {
        void *bindings;
        void *parent;
    } *env;
    struct {
        void *bindings;
    } *rule;
};

struct evalstring {
    bool visited;
    struct evalstringpart *parts;
};

struct evalstringpart {
    char *var;
    struct string *str;
    struct evalstringpart *next;
};

struct string *pathlist(struct pathlist *pl, size_t idx, char sep, bool escape);
struct string *treefind(void *bindings, char *var);
struct string *envvar(void *parent, char *var);
void fatal(const char *fmt, ...);
struct string *merge(struct evalstring *str, size_t n);