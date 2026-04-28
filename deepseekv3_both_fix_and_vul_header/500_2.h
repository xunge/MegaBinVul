#include <string>
#include <cstring>
#include <cstdint>

class binistream {
public:
    virtual ~binistream() {}
    virtual void readString(char*, int) = 0;
    virtual float readFloat(int) = 0;
    virtual int readInt(int) = 0;
    virtual bool error() = 0;
};

class CFileProvider {
public:
    virtual ~CFileProvider() {}
    virtual binistream* open(const std::string&) const = 0;
    virtual void close(binistream*) const = 0;
};

struct Channel {
    int defined;
};

struct Instrument {
    int value[8];
};

class CmkjPlayer {
public:
    bool load(const std::string &filename, const CFileProvider &fp);
    void rewind(int);
    void AdPlug_LogWrite(const char*, ...);

    int maxchannel;
    int maxnotes;
    short *songbuf;
    Channel channel[9];
    Instrument inst[9];
};

namespace binio {
    enum { Single };
}