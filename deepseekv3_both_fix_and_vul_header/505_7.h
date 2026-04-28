#include <string>
#include <cstring>

class binistream {
public:
    void readString(char*, int);
    unsigned long readInt(int);
};

class CFileProvider {
public:
    binistream* open(const std::string&) const;
    void close(binistream*) const;
};

namespace CmodPlayer {
    enum Flags {
        Opl3 = 1,
        Tremolo = 8,
        Vibrato = 16
    };
    extern unsigned int flags;
}

struct Tracks {
    unsigned char note;
    unsigned char inst;
    unsigned char command;
    unsigned char param1;
    unsigned char param2;
};

class Ca2mLoader {
public:
    static int nop;
    static int length;
    static int restartpos;
    static char songname[43];
    static char author[43];
    static char instname[250][33];
    struct Instrument {
        unsigned char data[11];
        unsigned char misc;
        unsigned char slide;
    };
    static Instrument inst[250];
    static unsigned char order[128];
    static unsigned char bpm;
    static unsigned char initspeed;
    static Tracks** tracks;
    
    bool load(const std::string &filename, const CFileProvider &fp);
    void realloc_patterns(int, int, int);
    void init_trackord();
    void rewind(int);
};

#define MAXBUF 65536

unsigned int sixdepak(unsigned short *src, unsigned char *dst, unsigned int len);

// Add enum values to global scope for backward compatibility
const int Opl3 = CmodPlayer::Opl3;
const int Tremolo = CmodPlayer::Tremolo;
const int Vibrato = CmodPlayer::Vibrato;