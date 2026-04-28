#include <stdio.h>
#include <string.h>

typedef struct sc_acl_entry {
    unsigned int method;
    unsigned int key_ref;
    struct sc_acl_entry *next;
} sc_acl_entry_t;

#define SC_AC_UNKNOWN 0
#define SC_AC_NEVER 1
#define SC_AC_NONE 2
#define SC_AC_CHV 3
#define SC_AC_TERM 4
#define SC_AC_PRO 5
#define SC_AC_AUT 6
#define SC_AC_SEN 7
#define SC_AC_SCB 8
#define SC_AC_IDA 9
#define SC_AC_KEY_REF_NONE 0