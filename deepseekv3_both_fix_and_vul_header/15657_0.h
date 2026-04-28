#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define NUL '\0'
#define FALSE 0
#define TRUE 1
#define FAIL 1
#define OK 0
#define OPT_MODELINE 0
#define OPT_FREE 0
#define UPD_CLEAR 0
#define ERR_BUFLEN 256
#define IOSIZE 1024

typedef unsigned char char_u;

char_u *skipwhite(char_u *p);
int STRNCMP(const char *s1, const char *s2, size_t n);
int ASCII_ISALPHA(int c);
void showoptions(int all, int opt_flags);
void set_options_default(int flags);
void didset_options(void);
void didset_options2(void);
void redraw_all_later(int type);
void show_termcodes(int opt_flags);
char *do_set_option(int opt_flags, char_u **argp, char_u *arg_start, char_u **startargp, int *did_show, int *stopopteval, char *errbuf, int errbuflen);
int VIM_ISWHITE(int c);
void vim_strncpy(char_u *to, char_u *from, size_t len);
size_t STRLEN(const char_u *str);
void STRCAT(char_u *to, const char *from);
void mch_memmove(void *dest, const void *src, size_t n);
void trans_characters(char_u *buf, size_t len);
void emsg(char *s);
void msg_putchar(char c);
void cursor_on(void);
void out_flush(void);

extern char_u IObuff[IOSIZE];
extern int silent_mode;
extern int info_message;
extern int no_wait_return;