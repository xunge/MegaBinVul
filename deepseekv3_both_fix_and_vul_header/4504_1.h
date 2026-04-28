#include <stdlib.h>
#include <math.h>

#define gFalse 0
#define gTrue 1
#define errSyntaxError 0
#define funcMaxOutputs 0
#define unlikely(x) (x)

typedef struct Object Object;
typedef struct Dict Dict;

struct Object {
    int isArray();
    int arrayGetLength();
    void arrayGet(int i, Object *obj);
    int isNum();
    double getNum();
    void free();
};

struct Dict {
    Object* lookup(const char *key, Object *obj);
};

struct ExponentialFunction {
    ExponentialFunction(Object *funcObj, Dict *dict);
};

int m;
int n;
int hasRange;
int ok;
int isLinear;
double c0[funcMaxOutputs];
double c1[funcMaxOutputs];
double e;

int init(Dict *dict);
void error(int err, int code, const char *msg);