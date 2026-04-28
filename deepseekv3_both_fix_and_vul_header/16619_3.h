#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <stdexcept>
#include <cstdio>

#define NUM_BUF_SIZE 512
#define S_NULL_LEN 6
#define FLOAT_DIGITS 6
#define NUL '\0'
#define YES 1
#define NO 0
#define LCONV_DECIMAL_POINT (localeconv()->decimal_point[0])

typedef long long wide_int;
typedef unsigned long long u_wide_int;

enum length_modifier_e {
    LM_STD,
    LM_LONG,
    LM_LONG_DOUBLE,
    LM_LONG_LONG,
    LM_SIZE_T,
    LM_INTMAX_T,
    LM_PTRDIFF_T
};

typedef enum length_modifier_e length_modifier_e;
typedef int boolean_e;

static const char s_null[] = "(null)";

#define STR_TO_DEC(str, var) \
    do { \
        var = 0; \
        while (isdigit((int)*str)) { \
            var = var * 10 + (*str - '0'); \
            str++; \
        } \
    } while (0)

#define FIX_PRECISION(adjust, prec, s, len) \
    do { \
        if (adjust) { \
            if (len > prec) { \
                s += len - prec; \
                len = prec; \
            } \
        } \
    } while (0)

class Exception : public std::exception {
private:
    char msg[256];
public:
    Exception(const char* format, ...) {
        va_list args;
        va_start(args, format);
        vsnprintf(msg, sizeof(msg), format, args);
        va_end(args);
    }
    const char* what() const noexcept override {
        return msg;
    }
};

static void appendchar(char **result, int *outpos, int *size, char c) {
    if (*outpos >= *size - 1) {
        *size *= 2;
        *result = (char *)realloc(*result, *size);
    }
    (*result)[(*outpos)++] = c;
}

static void appendsimplestring(char **result, int *outpos, int *size, const char *s, int len) {
    while (len-- > 0) {
        appendchar(result, outpos, size, *s++);
    }
}

static char *ap_php_conv_10(wide_int num, int is_unsigned, int *is_negative, char *buf_end, int *len) {
    return buf_end;
}

static char *ap_php_conv_p2(u_wide_int num, int nbits, char fmt, char *buf_end, int *len) {
    return buf_end;
}

static char *php_conv_fp(char format, double num, int add_dp, int precision, char dec_point, int *is_negative, char *buf, int *len) {
    return buf;
}

static char *php_gcvt(double value, int ndigit, char dec_point, char exponent, char *buf) {
    return buf;
}