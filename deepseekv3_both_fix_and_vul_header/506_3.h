#include <string>
#include <cstring>

struct binistream {
    virtual ~binistream() {}
    virtual void readString(char* str, int len) = 0;
    virtual unsigned char readInt(int bytes) = 0;
    virtual bool error() = 0;
    virtual void seek(unsigned short pos) = 0;
    virtual void close() = 0;
};

class CFileProvider {
public:
    virtual binistream* open(const std::string& filename) const = 0;
    virtual void close(binistream* stream) const = 0;
};

struct Track {
    unsigned char note;
    unsigned char inst;
    unsigned char command;
    unsigned char param1;
    unsigned char param2;
};

struct Instrument {
    unsigned char data[11];
};

class CradLoader {
public:
    bool load(const std::string &filename, const CFileProvider &fp);

private:
    unsigned char version;
    unsigned char radflags;
    char desc[80 * 22];
    Instrument inst[250];
    unsigned char length;
    unsigned char order[128];
    Track tracks[32 * 9][64];
    unsigned short trackord[32][9 * 2];
    unsigned char restartpos;
    unsigned char initspeed;
    unsigned char bpm;
    enum { Decimal } flags;

    void init_trackord();
    void rewind(int pos);
};