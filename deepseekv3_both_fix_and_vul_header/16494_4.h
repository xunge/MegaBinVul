#include <pwd.h>
#include <stddef.h>

struct rule {
    int options;
    const char **envlist;
};

struct env;

struct env *createenv(const struct rule *rule, ...);
void fillenv(struct env *env, const char **envlist);
char **flattenenv(struct env *env);

#define KEEPENV 0x01