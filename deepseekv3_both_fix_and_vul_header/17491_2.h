#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

struct config {
    char configfile[256];
    char lockfile[256];
    int type;
    char site[256];
};

struct booth_conf {
    char authfile[256];
    char name[256];
};

struct site {
    int local;
};

static struct config cl;
static struct booth_conf *booth_conf;
static struct site *local;

#define DAEMON 1
#define CLIENT 2
#define GEOSTORE 3
#define BOOTH_RUN_DIR "/var/run"
#define HAVE_LIBGCRYPT 0

int read_config(const char *configfile, int type);
int read_authkey(void);
int find_site_by_name(const char *name, struct site **site, int flag);
int find_myself(void *arg, int flag);
int check_config(int type);
void log_error(const char *format, ...);