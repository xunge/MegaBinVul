#include <cstdio>
#include <cstdlib>

#define BUFFER_INITIAL_SIZE 4096
#define OPJ_CODEC_JP2 0
#define OPJ_CLRSPC_SRGB 1
#define OPJ_CLRSPC_SYCC 2
#define errSyntaxWarning 0

class Object {
public:
    bool isInt() const;
    bool isArray() const;
    bool isName(const char*) const;
    int getInt() const;
    int arrayGetLength() const;
    Object arrayGet(int) const;
};

class Dict {
public:
    Object lookup(const char*) const;
};

class Stream {
public:
    unsigned char* toUnsignedChars(int* length, int bufSize);
};

struct JPXStreamPrivate {
    void init2(int codec, unsigned char* buf, int length, bool indexed);
    int smaskInData;
    struct opj_image* image;
    int npixels;
    int ncomps;
    int counter;
    int ccounter;
    bool inited;
};

struct opj_image_comp {
    int w;
    int h;
    int prec;
    bool sgnd;
    int* data;
};

struct opj_image {
    int numcomps;
    int color_space;
    opj_image_comp* comps;
};

class JPXStream {
public:
    void init();
    Dict* getDict() const;
    void close();
    Stream* str;
    JPXStreamPrivate* priv;
};

void error(int, int, const char*, int);
void gfree(void*);
unsigned char adjustComp(int, int, int, int, bool);