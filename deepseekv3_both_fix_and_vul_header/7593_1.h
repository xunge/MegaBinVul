#include <stdio.h>
#include <string.h>
#include <iconv.h>

#define SHORT_STRING 1024
#define BUFI_SIZE 4096

typedef long long LOFF_T;

typedef struct STATE {
    FILE *fpin;
} STATE;

static int mutt_strlen(const char *s);
static int mutt_strncmp(const char *s1, const char *s2, size_t n);
#define ISSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
static char decode_byte(char c);
static void mutt_convert_to_state(iconv_t cd, const char *buf, size_t *k, STATE *s);
static void state_set_prefix(STATE *s);
static void state_reset_prefix(STATE *s);