#include <cassert>
#include <string>

#define CV_XML_OPENING_TAG 0
#define CV_XML_CLOSING_TAG 1
#define CV_XML_HEADER_TAG 2
#define CV_XML_DIRECTIVE_TAG 3
#define CV_XML_EMPTY_TAG 4
#define CV_XML_INSIDE_TAG 0

#define CV_PARSE_ERROR_CPP(msg) assert(0 && msg)
#define CV_PERSISTENCE_CHECK_END_OF_BUFFER_BUG_CPP()
#define CV_Assert(expr) assert(expr)

inline bool cv_isalnum(char c) { return isalnum(c); }
inline bool cv_isalpha(char c) { return isalpha(c); }
inline bool cv_isspace(char c) { return isspace(c); }

char* skipSpaces(char* ptr, int flags);