#include <assert.h>
#include <ctype.h>

#define CV_XML_INSIDE_COMMENT 1
#define CV_XML_INSIDE_DIRECTIVE 2

#define cv_isprint_or_tab(c) (isprint((c)) || ((c) == '\t'))
#define cv_isprint(c) (isprint((c)))

struct FileStorage {
    char* (*gets)(void);
};

extern struct FileStorage* fs;

#define CV_PARSE_ERROR_CPP(msg) { /* error handling */ }