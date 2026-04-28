#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

enum url_scheme {
    SCHEME_INVALID,
    SCHEME_HTTP,
    SCHEME_HTTPS,
    SCHEME_FTP
};

#define scm_has_params    (1 << 0)
#define scm_has_query     (1 << 1)
#define scm_has_fragment  (1 << 2)

struct url {
    enum url_scheme scheme;
    char *host;
    int port;
    char *user;
    char *passwd;
    char *path;
    char *dir;
    char *file;
    char *params;
    char *query;
    char *fragment;
    char *url;
    bool idn_allocated;
};

struct iri {
    bool utf8_encode;
    char *orig_url;
};

struct {
    const char *leading_string;
    int flags;
} supported_schemes[] = {
    [SCHEME_HTTP] = { "http://", scm_has_query | scm_has_fragment },
    [SCHEME_HTTPS] = { "https://", scm_has_query | scm_has_fragment },
    [SCHEME_FTP] = { "ftp://", scm_has_params }
};

struct options {
    bool enable_iri;
} opt;

#define PE_UNSUPPORTED_SCHEME 1
#define PE_MISSING_SCHEME 2
#define PE_UNTERMINATED_IPV6_ADDRESS 3
#define PE_INVALID_IPV6_ADDRESS 4
#define PE_IPV6_NOT_SUPPORTED 5
#define PE_INVALID_HOST_NAME 6
#define PE_BAD_PORT_NUMBER 7
#define PE_INVALID_USER_NAME 8

#define URL_AUTH_SHOW 0
#define ENABLE_IPV6 1

#define xfree(ptr) free((void *)(ptr))
#define xnew0(type) ((type *)calloc(1, sizeof(type)))
#define xstrdup(str) strdup(str)

static enum url_scheme url_scheme(const char *url) { return SCHEME_INVALID; }
static bool url_has_scheme(const char *url) { return false; }
static char *remote_to_utf8(struct iri *iri, const char *str, char **new_str) { return NULL; }
static char *reencode_escapes(const char *str) { return NULL; }
static const char *url_skip_credentials(const char *p) { return p; }
static const char *init_seps(enum url_scheme scheme) { return ""; }
static const char *strpbrk_or_eos(const char *s, const char *accept) { return s + strlen(s); }
static int scheme_default_port(enum url_scheme scheme) { return 0; }
static bool parse_credentials(const char *start, const char *end, char **user, char **passwd) { return false; }
static char *strdupdelim(const char *beg, const char *end) { return NULL; }
static bool path_simplify(enum url_scheme scheme, char *path) { return false; }
static void split_path(char *path, char **dir, char **file) {}
static bool lowercase_str(char *str) { return false; }
static void url_unescape(char *str) {}
static char *idn_encode(struct iri *iri, const char *host) { return NULL; }
static char *url_string(struct url *u, int flags) { return NULL; }
static bool is_valid_ipv6_address(const char *start, const char *end) { return false; }
static bool c_isdigit(char c) { return c >= '0' && c <= '9'; }