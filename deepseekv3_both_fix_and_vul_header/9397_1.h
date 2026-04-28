#include <string>

class bdecode_error_category {
public:
    std::string message(int ev) const;
};

#define BOOST_SYSTEM_NOEXCEPT

static char const* msgs[] =
{
    "no error",
    "expected string in bencoded string",
    "expected colon in bencoded string",
    "unexpected end of file in bencoded string",
    "expected value (list, dict, int or string) in bencoded string",
    "bencoded nesting depth exceeded",
    "bencoded item count limit exceeded",
};