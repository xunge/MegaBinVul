#include <stddef.h>
#include <stdbool.h>

typedef struct typval_S typval_T;
typedef struct tabpage_S tabpage_T;
typedef unsigned char char_u;

#define FALSE false
#define TRUE true

struct typval_S {
    union {
        int v_number;
    } vval;
};

struct tabpage_S {
    // Add necessary fields here
};

extern int check_restricted(void);
extern int check_secure(void);
extern long tv_get_number_chk(typval_T *tv, char **arg_err);
extern char_u *tv_get_string_chk(typval_T *tv);
extern tabpage_T *find_tabpage(int n);
extern tabpage_T *curtab;
extern void goto_tabpage_tp(tabpage_T *tp, bool trigger_enter_autocmds, bool trigger_leave_autocmds);
extern char_u *alloc(unsigned size);
extern void STRCPY(char_u *to, const char_u *from);
extern size_t STRLEN(const char_u *str);
extern void set_var(char_u *name, typval_T *varp, bool copy);
extern void vim_free(void *ptr);
extern bool valid_tabpage(tabpage_T *tp);