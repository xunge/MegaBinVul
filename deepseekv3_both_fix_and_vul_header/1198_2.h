#include <cstring>
#include <cstdint>

#define MP_MAXINSSAMPS 16
#define MP_MAXORDERS 256
#define MP_MAXINS 128
#define MP_MAXSAMPLES 2048
#define XM_ENVELOPENUMPOINTS 12

typedef uint8_t mp_ubyte;
typedef int8_t mp_sbyte;
typedef uint16_t mp_uword;
typedef int16_t mp_sword;
typedef uint32_t mp_uint32;
typedef int32_t mp_sint32;

struct TXMHeader {
    char sig[17];
    char name[20];
    mp_ubyte whythis1a;
    char tracker[20];
    mp_uword ver;
    mp_uint32 hdrsize;
    mp_uword ordnum;
    mp_uword restart;
    mp_uword channum;
    mp_uword patnum;
    mp_uword insnum;
    mp_uword freqtab;
    mp_uword tempo;
    mp_uword speed;
    mp_ubyte ord[256];
    mp_ubyte mainvol;
    mp_uint32 flags;
    mp_ubyte uppernotebound;
    mp_ubyte pan[32];
    mp_uword smpnum;
    mp_uword volenvnum;
    mp_uword panenvnum;
};

struct TXMInstrument {
    mp_uint32 size;
    char name[22];
    mp_ubyte type;
    mp_uword samp;
    mp_uint32 shsize;
    mp_sbyte snum[120];
};

struct TXMSample {
    mp_uint32 samplen;
    mp_uint32 loopstart;
    mp_uint32 looplen;
    mp_ubyte vol;
    mp_sbyte finetune;
    mp_ubyte type;
    mp_ubyte pan;
    mp_sbyte relnote;
    mp_ubyte res;
    char name[22];
    mp_ubyte flags;
    mp_uword venvnum;
    mp_uword penvnum;
    mp_ubyte vibtype;
    mp_ubyte vibsweep;
    mp_ubyte vibdepth;
    mp_ubyte vibrate;
    mp_uword volfade;
    void* sample;
};

struct TXMPattern {
    mp_uint32 len;
    mp_ubyte ptype;
    mp_uword rows;
    mp_uword patdata;
    mp_ubyte effnum;
    mp_ubyte channum;
    mp_ubyte* patternData;
};

struct TEnvelope {
    mp_uword env[XM_ENVELOPENUMPOINTS][2];
    mp_ubyte num;
    mp_ubyte sustain;
    mp_ubyte loops;
    mp_ubyte loope;
    mp_ubyte type;
};

class XMFileBase {
public:
    virtual mp_uint32 sizeWithBaseOffset() = 0;
    virtual mp_uint32 posWithBaseOffset() = 0;
    virtual void read(void* buffer, mp_uint32 size, mp_uint32 count) = 0;
    virtual mp_ubyte readByte() = 0;
    virtual mp_uword readWord() = 0;
    virtual mp_uint32 readDword() = 0;
    virtual void readWords(mp_uword* buffer, mp_uint32 count) = 0;
    virtual void readDwords(mp_uint32* buffer, mp_uint32 count) = 0;
};

class XModule {
public:
    TXMHeader header;
    TXMInstrument* instr;
    TXMSample* smp;
    TXMPattern* phead;
    char* message;
    
    enum {
        MODULE_XMNOTECLIPPING = 1,
        MODULE_XMARPEGGIO = 2,
        MODULE_XMPORTANOTEBUFFER = 4,
        MODULE_XMVOLCOLUMNVIBRATO = 8
    };
    
    enum {
        NOTE_OFF = 97,
        ST_PACKING_ADPCM = 1,
        ST_DELTA = 2,
        ST_16BIT = 16
    };
    
    static const mp_ubyte validXMEffects[];
    static const mp_ubyte numValidXMEffects;
    
    void cleanUp();
    bool addVolumeEnvelope(const TEnvelope& env);
    bool addPanningEnvelope(const TEnvelope& env);
    mp_sint32 loadModuleSample(XMFileBase& f, mp_sint32 s, mp_uint32 flags, mp_uint32 desiredFlags, mp_uint32 oldSize);
    void postProcessSamples();
    void allocateSongMessage(mp_uint32 size);
    void addSongMessageLine(const char* line);
    static mp_ubyte vol64to255(mp_ubyte vol);
    static void convertStr(char* dest, const char* src, mp_sint32 len, bool utf8);
    static void convertXMVolumeEffects(mp_ubyte vol, mp_ubyte& outVol, mp_ubyte& outEff);
};

class LittleEndian {
public:
    static mp_uword GET_WORD(const mp_ubyte* ptr);
    static mp_uint32 GET_DWORD(const mp_ubyte* ptr);
};

class LoaderXM {
public:
    mp_sint32 load(XMFileBase& f, XModule* module);
};

#define MP_OK 0
#define MP_OUT_OF_MEMORY -1
#define MP_LOADER_FAILED -2