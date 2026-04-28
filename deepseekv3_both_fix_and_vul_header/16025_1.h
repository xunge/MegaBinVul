#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef int cmdidx_T;
typedef int getoption_T;
typedef int typval_T;
typedef int type_T;

typedef struct {
    void *ctx_type_list;
} cctx_T;

typedef enum {
    dest_option,
    dest_func_option,
    dest_env,
    dest_reg,
    dest_global,
    dest_buffer,
    dest_window,
    dest_tab,
    dest_vimvar
} assign_dest_T;

#define FALSE 0
#define OK 1
#define FAIL 0
#define CMD_final 0
#define CMD_const 0
#define NUL '\0'
#define STRNCMP strncmp
#define gov_unknown 0
#define gov_string 1
#define gov_hidden_string 2
#define gov_bool 3
#define gov_hidden_bool 4
#define gov_number 5
#define gov_hidden_number 6
#define P_FUNC 0

#define _(x) x
#define e_cannot_lock_option "E1030: Cannot lock option"
#define e_unexpected_characters_in_assignment "E488: Unexpected characters in assignment"
#define e_unknown_option_str "E518: Unknown option: %s"
#define e_variable_not_found_str "E121: Undefined variable: %s"

extern char_u *find_option_end(char_u **, int *);
extern getoption_T get_option_value(char_u *, long *, void *, int *, int);
extern int find_vim_var(char_u *, int *);
extern int var_check_ro(int, char_u *, int);
extern typval_T *get_vim_var_tv(int);
extern type_T *typval2type_vimvar(typval_T *, void *);
extern int valid_yank_reg(int, int);
extern void emsg(const char *);
extern void emsg_invreg(int);
extern void semsg(const char *, char_u *);
extern char_u *skip_option_env_lead(char_u *);

extern type_T t_any;
extern type_T t_string;
extern type_T t_bool;
extern type_T t_number;
extern type_T t_number_or_string;