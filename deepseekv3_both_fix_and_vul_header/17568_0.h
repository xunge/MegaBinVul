#include <stdlib.h>
#include <string.h>

struct credential {
    char *username;
    char *password;
    char *protocol;
    char *host;
    char *path;
};

#define CREDENTIAL_INIT { NULL, NULL, NULL, NULL, NULL }

static int looks_like_command_line_option(const char *url);
static int submodule_url_is_relative(const char *url);
static char *url_decode(const char *url);
static int url_to_curl_url(const char *url, const char **curl_url);
static int credential_from_url_gently(struct credential *c, const char *url, int quiet);
static void credential_clear(struct credential *c);