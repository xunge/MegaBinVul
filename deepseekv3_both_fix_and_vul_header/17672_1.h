#include <stddef.h>

#define NUMBUFLEN 100
typedef unsigned char char_u;

typedef struct {
    // 定义typval_T结构体成员
    // 这里只声明结构体类型，实际成员根据需求补充
} typval_T;

char_u *tv_get_string_buf(typval_T *var, char_u *buf);
void do_luaeval(char_u *str, typval_T *args, typval_T *rettv);