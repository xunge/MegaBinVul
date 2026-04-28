#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define GDB_NAME_SZ 15
#define GDB_GROUPS_SZ 127
#define GDB_TYPE_SZ 15

typedef unsigned char ut8;
typedef struct rz_str_buf_t RzStrBuf;

RzStrBuf *rz_strbuf_new(const char *s);
void rz_strbuf_free(RzStrBuf *sb);
char *rz_strbuf_drain(RzStrBuf *sb);
void rz_strbuf_appendf(RzStrBuf *sb, const char *fmt, ...);
const char *rz_str_trim_head_ro(const char *s);
bool rz_str_startswith(const char *str, const char *needle);
#define rz_return_val_if_fail(cond, val) if (!(cond)) return val
#define RZ_STR_DEF(n) #n