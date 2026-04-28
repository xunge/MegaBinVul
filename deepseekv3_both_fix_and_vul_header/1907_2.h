#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define DESLEN 13
#define AUTH_SUCCESS 1
#define AUTH_FAILURE 0
#define SUDOERS_DEBUG_AUTH 0

typedef struct sudo_auth {
    char *data;
} sudo_auth;

typedef struct sudo_conv_callback {
    // dummy definition since actual members are not used in this function
} sudo_conv_callback;

#define HAS_AGEINFO(p, l) ((l) > DESLEN && (p)[DESLEN] == ',')

#define debug_decl(func, flags)
#define debug_return_int(ret) return (ret)