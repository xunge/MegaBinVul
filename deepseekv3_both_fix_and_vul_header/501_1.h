#include <stdbool.h>
#include <assert.h>

class CmkjPlayer {
public:
    bool update();
};

struct Channel {
    bool defined;
    int pstat;
    int songptr;
    int octave;
    int speed;
    int waveform;
};

class OPL {
public:
    void write(int reg, int val);
};

extern int maxchannel;
extern int maxnotes;
extern Channel channel[];
extern short songbuf[];
extern OPL* opl;
extern bool songend;