#include <memory>

class Dict {
public:
    class Object lookup(const char *key);
};

class Object {
public:
    bool isArray();
    bool isDict();
    bool isString();
    bool isNull();
    int arrayGetLength();
    Object arrayGet(int index);
    Dict *getDict();
    const char *getString();
    Object();
    Object(const Object &other);
    Object &operator=(const Object &other);
    ~Object();
};

class GooString {
public:
    GooString(const char *str);
    ~GooString();
};

namespace AnnotRichMedia {
    class Configuration {
    public:
        Configuration(Dict *dict);
    };

    class Asset {
    public:
        std::unique_ptr<GooString> name;
        Object fileSpec;
    };

    class Content {
    public:
        Content(Dict *dict);
    private:
        int nConfigurations;
        Configuration **configurations;
        int nAssets;
        Asset **assets;
    };
}

enum ErrorCategory {
    errSyntaxError
};

extern "C" {
    void *gmallocn(int numElems, size_t elemSize);
    void error(int category, int code, const char *msg, ...);
}