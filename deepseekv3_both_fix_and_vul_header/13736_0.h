#include <stddef.h>

typedef unsigned char u8;

#define SC_AC_OP_DELETE 0
#define SC_AC_OP_CREATE 1
#define SC_AC_OP_INVALIDATE 2
#define SC_AC_OP_REHABILITATE 3
#define SC_AC_OP_LOCK 4
#define SC_AC_OP_READ 5
#define SC_AC_OP_UPDATE 6
#define SC_AC_OP_WRITE 7
#define SC_AC_OP_ERASE 8
#define SC_AC_OP_CRYPTO 9
#define SC_AC_OP_SELECT 10

#define SC_AC_NONE 0
#define SC_AC_TERM 1
#define SC_AC_AUT 2
#define SC_AC_PRO 3
#define SC_AC_CHV 4

typedef enum {
    SC_FILE_TYPE_DF,
    SC_FILE_TYPE_INTERNAL_EF,
    SC_FILE_TYPE_WORKING_EF
} sc_file_type_t;

typedef struct sc_file_t {
    sc_file_type_t type;
    void (*add_acl_entry)(struct sc_file_t *, int, int, int);
} sc_file_t;