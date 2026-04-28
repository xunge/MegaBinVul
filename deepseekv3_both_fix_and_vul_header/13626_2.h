#include <stdio.h>

#define maxArgs 128
#define GBool int

class GooString;

class Object {
public:
    bool isEOF();
    bool isCmd();
    void print(FILE *fp);
    void free();
    const char *getCmd();
    void getObj(Object *obj);
};

class GooTimer {
public:
    double getElapsed();
};

class GooHash {
public:
    void *lookup(GooString *key);
    void add(GooString *key, void *value);
};

class GooString {
public:
    GooString(const char *s);
    ~GooString();
};

class ProfileData {
public:
    void addElement(double elapsed);
};

class OutputDev {
public:
    void dump();
    GooHash *getProfileHash();
};

class Gfx {
public:
    void go(GBool topLevel);
    void pushStateGuard();
    void popStateGuard();
    void execOp(Object *obj, Object *args, int numArgs);
    void error(int pos, const char *msg);
    int getPos();
    
    Object *parser;
    bool printCommands;
    bool profileCommands;
    bool (*abortCheckCbk)(void *);
    void *abortCheckCbkData;
    int updateLevel;
    OutputDev *out;
};