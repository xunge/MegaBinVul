#include <string.h>
#include <stddef.h>

#define ERR_BUFLEN 80
#define KS_KEY 0x80
#define KEY2TERMCAP0(k) ((k) >> 8)
#define KEY2TERMCAP1(k) ((k) & 0xff)
#define P_SECURE 0x01
#define P_STRING 0x02
#define P_NUM 0x04
#define OPT_LOCAL 1
#define UPD_CLEAR 1
#define FALSE 0
#define NUL '\0'

typedef unsigned char char_u;
typedef unsigned long long_u;
typedef int int32_t;

extern int32_t findoption(char_u *name);
extern int find_key_option(char_u *name, int flag);
extern void add_termcode(char_u *key_name, char_u *string, int flag);
extern void ttest(int flag);
extern void redraw_all_later(int flag);
extern char *set_string_option(int opt_idx, char_u *string, int opt_flags, char *errbuf, ...);
extern char *set_num_option(int opt_idx, char_u *varp, long number, char *errbuf, size_t errbuf_size, int opt_flags);
extern char *set_bool_option(int opt_idx, char_u *varp, int number, int opt_flags);
extern char_u *get_varp_scope(void *option, int opt_flags);
extern void semsg(const char *msg, ...);
extern void emsg(const char *msg);
extern const char *e_unknown_option_str_2;
extern const char *e_not_allowed_in_sandbox;
extern const char *e_number_required_after_str_equal_str;

#define STRLEN(s) strlen((const char *)(s))
#define _(s) s

struct vimoption {
    long_u flags;
    // other members...
};

extern struct vimoption options[];
extern int full_screen;
extern int sandbox;