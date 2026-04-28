#include <stdlib.h>
#include <string.h>
#include <errno.h>

enum URIState {
    URI_STATE_INVALID,
    URI_STATE_ERROR,
    URI_STATE_SUCCESS
};

enum URIPart {
    URI_SCHEME,
    URI_USERINFO,
    URI_HOST,
    URI_PORT,
    URI_PATH,
    URI_QUERY,
    URI_FRAGMENT,
    URI_PART_ELEMENTS
};

struct ParsedURI {
    char *scheme;
    char *userinfo;
    char *host;
    char *port;
    char *path;
    char *query;
    char *fragment;
    enum URIState state;
    int error;
};

class URIParser {
public:
    static int parse(const char *str, ParsedURI& uri);
};

extern const bool valid_char[URI_PART_ELEMENTS][256];
extern const int authority_map[256];