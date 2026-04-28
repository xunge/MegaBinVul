#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <locale.h>
#include <libintl.h>
#include <sys/types.h>

#define _(String) gettext(String)
#define USAGE_HEADER ""
#define USAGE_SEPARATOR ""
#define USAGE_OPTIONS ""
#define USAGE_HELP_OPTIONS(x) ""
#define USAGE_COLUMNS ""
#define USAGE_MAN_TAIL(x) ""
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

extern char *program_invocation_short_name;

struct info {
    const char *name;
    const char *help;
};

static struct info infos[] = {
    {NULL, NULL}
};