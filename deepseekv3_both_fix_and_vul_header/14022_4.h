#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <err.h>
#include <locale.h>
#include <libintl.h>

#define _(String) gettext(String)

struct chfn_control {
    struct {
        char *full_name;
        char *office;
        char *office_phone;
        char *home_phone;
        char *other;
    } newf;
    char *username;
    struct passwd *pw;
};

extern int xasprintf(char **strp, const char *fmt, ...);
extern int setpwnam(struct passwd *pw, ...);
extern int set_value_libuser(const char *caller, const char *username, uid_t uid, int field, const char *value);