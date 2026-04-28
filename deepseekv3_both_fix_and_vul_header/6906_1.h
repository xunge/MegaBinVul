#include <stddef.h>
#include <stdbool.h>

#define NUL '\0'
#define NL '\n'
#define CAR '\r'
#define TRUE true
#define FALSE false

typedef char char_u;

static bool silent_mode;
static int p_verbose;
static bool info_message;
static int msg_col;
static int Columns;
static bool cmdmsg_rl;
static bool msg_didout;

#define FEAT_RIGHTLEFT
#define MSWIN

void mch_settmode(int mode);
void mch_msg(const char *str);
void mch_errmsg(const char *str);
char_u *alloc(size_t size);
void vim_free(void *ptr);
char_u *vim_strnsave(const char_u *str, size_t len);
#define STRLEN strlen
size_t strlen(const char *s);
void *memcpy(void *dest, const void *src, size_t n);

#define TMODE_COOK 0
#define TMODE_RAW 1