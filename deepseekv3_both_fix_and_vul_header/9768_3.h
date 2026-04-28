#include <stdlib.h>
#include <string.h>

class Stream;
class GooString;
class PSStack;
class PopplerCache;

class Dict {};

class Object {
public:
    bool isStream();
    Stream* getStream();
};

class Stream {
public:
    void reset();
    void close();
};

class GooString {
public:
    bool cmp(const char* str);
};

class PSStack {};
class PopplerCache {
public:
    PopplerCache(int size);
};

#define gFalse false
#define gTrue true

class PostScriptFunction {
public:
    PostScriptFunction(Object *funcObj, Dict *dict);
private:
    char *code;
    GooString *codeString;
    int codeSize;
    bool ok;
    PopplerCache *cache;
    PSStack *stack;
    bool hasRange;

    bool init(Dict *dict);
    GooString *getToken(Stream *str);
    bool parseCode(Stream *str, int *codePtr);
    void error(int code, const char *msg);
};