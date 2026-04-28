#include <cstring>
#include <string>

class binistream {
public:
    virtual ~binistream() {}
    virtual void readString(char*, int) = 0;
    virtual unsigned short readInt(int) = 0;
};

class CFileProvider {
public:
    virtual ~CFileProvider() {}
    virtual binistream* open(const std::string&) const = 0;
    virtual void close(binistream*) const = 0;
    virtual unsigned long filesize(binistream*) const = 0;
};

struct CmtkLoader {
    char title[34];
    char composer[34];
    char instname[0x80][34];
    unsigned char instr[0x80][12];
    unsigned char song[0x80];
    unsigned char patterns[0x32][0x40][9];
    
    void rewind(int);
    bool load(const std::string&, const CFileProvider&);
};