#include <stddef.h>
#include <string.h>
#include <wchar.h>

#define NUMBUFLEN 100
#define MB_MAXBYTES 6
#define K_IGNORE 0
#define K_VER_SCROLLBAR 0
#define K_HOR_SCROLLBAR 0
#define NUL '\0'
#define Ctrl_C 3
#define CAR '\r'
#define K_KENTER 0
#define NL '\n'
#define OK 1
#define TRUE 1
#define FALSE 0

typedef wchar_t char_u;

typedef enum {
    PASTE_CMDLINE,
    PASTE_EX, 
    PASTE_INSERT,
    PASTE_ONE_CHAR
} paste_mode_T;

typedef struct {
    char *ga_data;
    int ga_len;
} garray_T;

extern int no_mapping;
extern int allow_keys;
extern int p_paste;
extern int got_int;
extern int ex_normal_busy;
extern int has_mbyte;
extern int (*mb_char2bytes)(int, char_u *);
extern int (*mb_ptr2char)(char_u *);

#define STRLEN wcslen
#define STRNCMP wcsncmp

char_u *find_termcode(char_u *);
int vpeekc(void);
int vgetc(void);
void put_on_cmdline(char_u *, int, int);
int ga_grow(garray_T *, int);
void mch_memmove(void *, const void *, size_t);
int stop_arrow(void);
void ins_eol(int);
void ins_char_bytes(char_u *, int);
void AppendToRedobuffLit(char_u *, int);
void set_option_value(char_u *, int, void *, int);