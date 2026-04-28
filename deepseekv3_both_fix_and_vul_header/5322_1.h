#include <stdint.h>
#include <math.h>
#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Buffer js_Buffer;

struct js_Object {
    int type;
    union {
        double number;
    } u;
};

struct js_Buffer {
    char *s;
};

enum {
    JS_CNUMBER,
};