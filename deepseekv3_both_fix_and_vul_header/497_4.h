#include <string>
#include <cstring>

struct binistream {
    virtual ~binistream() {}
    virtual void readString(char* buf, int len) = 0;
    virtual int readInt(int bytes) = 0;
    virtual bool error() const = 0;
    virtual void ignore(int n) = 0;
};

struct CFileProvider {
    virtual ~CFileProvider() {}
    virtual binistream* open(const std::string& filename) const = 0;
    virtual void close(binistream* f) const = 0;
};

class CdtmLoader {
public:
    bool load(const std::string &filename, const CFileProvider &fp);
    void realloc_instruments(int num);
    void realloc_order(int num);
    void realloc_patterns(int num, int rows, int channels);
    void init_notetable(const unsigned short* notes);
    void init_trackord();
    void rewind(int pos);
    long unpack_pattern(const unsigned char* packed, long packed_len, unsigned char* unpacked, long unpacked_len);
};

struct dtm_event {
    unsigned char byte0;
    unsigned char byte1;
};

struct {
    char id[12];
    int version;
    char title[20];
    char author[20];
    int numpat;
    int numinst;
} header;

struct Instrument {
    char name[256];
    unsigned char data[12];
} instruments[256];

struct {
    unsigned char data[12];
} inst[256];

struct TrackEvent {
    unsigned char note;
    unsigned char inst;
    unsigned char command;
    unsigned char param1;
    unsigned char param2;
} tracks[256][64];

char desc[80*16 + 16 + 1];
unsigned char order[100];
int nop;
int length;
int restartpos;
int initspeed;