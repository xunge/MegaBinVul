#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>

#define MAXREC 1000

typedef struct Resub {
    struct {
        const char *sp;
        const char *ep;
    } sub[10];
} Resub;

typedef struct Reinst {
    int opcode;
    int n;
    wint_t c;
    struct Reinst *x;
    struct Reinst *y;
    char *cc;
} Reinst;

typedef wint_t Rune;

enum {
    I_END,
    I_JUMP,
    I_SPLIT,
    I_PLA,
    I_NLA,
    I_ANYNL,
    I_ANY,
    I_CHAR,
    I_CCLASS,
    I_NCCLASS,
    I_REF,
    I_BOL,
    I_EOL,
    I_WORD,
    I_NWORD,
    I_LPAR,
    I_RPAR
};

enum {
    REG_ICASE = 1,
    REG_NEWLINE = 2,
    REG_NOTBOL = 4
};

static int chartorune(Rune *rune, const char *str) {
    *rune = (Rune)*str;
    return 1;
}

static int isnewline(Rune c) {
    return c == '\n' || c == '\r';
}

static int iswordchar(Rune c) {
    return isalnum(c) || c == '_';
}

static Rune canon(Rune c) {
    return towlower(c);
}

static int incclass(char *cc, Rune c) {
    return strchr(cc, c) != NULL;
}

static int incclasscanon(char *cc, Rune c) {
    return strchr(cc, towlower(c)) != NULL || strchr(cc, toupper(c)) != NULL;
}

static int strncmpcanon(const char *s1, const char *s2, size_t n) {
    while (n--) {
        Rune c1 = canon(*s1++);
        Rune c2 = canon(*s2++);
        if (c1 != c2) return c1 - c2;
    }
    return 0;
}