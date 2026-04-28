#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int (*PrintfCallback)(const char *format, ...);

typedef struct Sdb Sdb;

#define SDB_NUM_BUFSZ 64
#define PFMT64x "llx"
#define PFMT64d "lld"

typedef uint64_t ut64;

char *r_str_newf(const char *fmt, ...);
const char *r_str_rchr(const char *str, const char *end, int ch);
void r_str_ansi_strip(char *str);
void r_str_replace_ch(char *str, int from, int to, bool last);
char *sdb_itoa(ut64 num, int base, char *out, int out_len);
void sdb_add(Sdb *s, const char *key, const char *val, int cas);