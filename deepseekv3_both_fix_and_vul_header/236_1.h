#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define R_API
#define R_BUF_SET 0

typedef struct r_buf_t RBuffer;
typedef uint8_t ut8;

struct r_egg_t {
    RBuffer *src;
    struct {
        int elem_n;
        char elem[1024];
    } lang;
    int context;
    void *remit;
};

typedef struct r_egg_t REgg;

int r_buf_seek(RBuffer *buf, int offset, int whence);
int r_buf_read(RBuffer *buf, ut8 *data, int len);
void r_egg_lang_init(REgg *egg);
void r_egg_lang_parsechar(REgg *egg, char b);