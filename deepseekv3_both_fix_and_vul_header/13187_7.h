#include <cstring>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <cstdarg>

#define ME_META 0xFF
#define META_EOT 0x2F

using qint64 = int64_t;

class QString {
public:
    QString(const char* str);
};

class MidiEvent {
public:
    int type();
    int metaType();
};

class MidiTrack {
public:
    void setOutPort(int port);
    void setOutChannel(int channel);
    void insert(qint64 click, const MidiEvent& event);
};

class FilePointer {
public:
    void skip(qint64 bytes);
};

class LOGW {
public:
    void operator()(const char* format, ...) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
};

extern LOGW LOGW;
extern FilePointer* fp;

class MidiFile {
public:
    bool readTrack();
};

qint64 curPos;
int status;
int sstatus;
qint64 click;
std::vector<MidiTrack> _tracks;

void read(char* buf, int size);
int readLong();
bool readEvent(MidiEvent* event);
void skip(qint64 bytes);