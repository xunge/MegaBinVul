#include <stdint.h>
#include <limits.h>

namespace boost {
    typedef int64_t int64_t;
}

namespace bdecode_errors {
    enum error_code_enum {
        expected_string,
        overflow,
        expected_colon
    };
}

inline bool numeric(char c) {
    return c >= '0' && c <= '9';
}

inline bool is_digit(char c) {
    return c >= '0' && c <= '9';
}