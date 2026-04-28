#include <ctype.h>
#include <stddef.h>

#define NUL 0
#define ESC 0x1b
#define CSI 0x9b
#define OSC 0x9d
#define DCS 0x90
#define K_SPECIAL 0x80
#define KS_EXTRA 0x80
#define KS_MOUSE 0x80
#define KS_KEY 0x80
#define KS_DEC_MOUSE 0x80
#define KS_PTERM_MOUSE 0x80
#define KS_SGR_MOUSE 0x80
#define KS_SGR_MOUSE_RELEASE 0x80
#define KS_URXVT_MOUSE 0x80
#define KS_GPM_MOUSE 0x80
#define KS_JSBTERM_MOUSE 0x80
#define KS_NETTERM_MOUSE 0x80
#define KS_MENU 0x80
#define KS_TABLINE 0x80
#define KS_TABMENU 0x80
#define KS_VER_SCROLLBAR 0x80
#define KS_HOR_SCROLLBAR 0x80
#define KE_IGNORE 0x80
#define KE_FILLER 0x80
#define KE_FOCUSGAINED 0x80
#define KE_FOCUSLOST 0x80
#define KE_X1MOUSE 0x80
#define KE_X2MOUSE 0x80
#define KE_MOUSEMOVE_XY 0x80
#define KE_MOUSELEFT 0x80
#define KE_MOUSERIGHT 0x80
#define KE_MOUSEDOWN 0x80
#define KE_MOUSEUP 0x80
#define KE_MOUSEMOVE 0x80
#define CPO_KOFFSET 'K'
#define MAX_KEY_CODE_LEN 50
#define KEYLEN_REMOVED (-2)
#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define MODE_INSERT 0x01
#define STATUS_SENT 1

typedef unsigned char char_u;
typedef unsigned long long_u;

struct typebuf {
    char_u *tb_buf;
    int tb_off;
    int tb_len;
};

struct termcode {
    char_u *code;
    int len;
    char_u name[2];
    int modlen;
};

struct trs_status {
    int tr_progress;
};

extern char_u *p_cpo;
extern char_u *p_ek;
extern char_u *termleader;
extern char_u *T_RBG;
extern char_u *T_RFG;
extern struct typebuf typebuf;
extern struct termcode *termcodes;
extern int tc_len;
extern int need_gather;
extern int State;
extern int focus_state;
extern int did_cursorhold;
extern int current_tab;
extern int current_tabmenu;
extern int current_scrollbar;
extern long_u scrollbar_value;
extern int mouse_col;
extern int mouse_row;
extern int check_for_codes;
extern struct trs_status rcs_status;
extern int has_mbyte;
extern int (*mb_char2bytes)(int, char_u *);

#define VIM_ISDIGIT(c) isdigit((unsigned char)(c))
#define STRNCMP(s1, s2, n) strncmp((const char *)(s1), (const char *)(s2), (n))
#define TERMCAP2KEY(a, b) ((a) << 8 | (b))
#define KEY2TERMCAP0(k) (((k) >> 8) & 0xff)
#define KEY2TERMCAP1(k) ((k) & 0xff)
#define decode_modifiers(n) (n)
#define handle_x_keys(k) (k)
#define modifiers2keycode(mods, key, str) 0
#define put_string_in_typebuf(off, slen, str, new_slen, buf, bufsize, buflen) 0
#define check_termcode_mouse(tp, slen, key_name, mod_start, idx, mods) 0
#define handle_csi(tp, len, argp, off, buf, bufsize, buflen, key_name, slen) 0
#define handle_osc(tp, argp, len, key_name, slen) 0
#define handle_dcs(tp, argp, len, key_name, slen) 0
#define get_bytes_from_buf(src, dest, count) 0
#define get_long_from_buf(src, dest) 0
#define getdigits(pp) 0
#define vim_strchr(s, c) strchr((const char *)(s), (c))
#define gather_termleader()
#define ui_focus_change(flag)