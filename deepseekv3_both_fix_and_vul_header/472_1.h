#include <cstring>
#include <cstdint>
#include <cstdio>

#define MP_OUT_OF_MEMORY -1
#define MP_LOADER_FAILED -2
#define MP_OK 0
#define MP_MAXINS 256
#define VERBOSE 0

typedef uint8_t mp_ubyte;
typedef uint16_t mp_uword;
typedef uint32_t mp_uint32;
typedef int32_t mp_sint32;

struct XMFileBase {
    mp_ubyte readByte();
    mp_uword readWord();
    mp_uint32 readDword();
    void read(void* buf, size_t size, size_t count);
    void readWords(mp_uword* buf, size_t count);
    void seekWithBaseOffset(mp_uint32 offset);
};

struct TXMSample {
    char name[12];
    mp_uint32 samplen;
    mp_uint32 loopstart;
    mp_uint32 looplen;
    mp_ubyte vol;
    mp_ubyte pan;
    mp_ubyte flags;
    mp_ubyte type;
    mp_ubyte res;
    mp_sint32 finetune;
    mp_sint32 relnote;
};

struct TXMInstrument {
    char name[28];
    mp_ubyte samp;
    mp_ubyte snum[120];
};

struct TXMPattern {
    // Pattern data structure
};

struct TXMHeader {
    char name[28];
    mp_ubyte whythis1a;
    mp_uword ordnum;
    mp_uword insnum;
    mp_uword patnum;
    mp_uword flags;
    mp_ubyte mainvol;
    mp_ubyte tempo;
    mp_ubyte speed;
    mp_ubyte channum;
    char sig[4];
    mp_ubyte ord[256];
    char tracker[16];
    mp_uword smpnum;
};

struct XModule {
    TXMHeader header;
    TXMInstrument* instr;
    TXMSample* smp;
    TXMPattern* phead;
    
    void cleanUp();
    mp_ubyte vol64to255(mp_ubyte vol);
    static void convertc4spd(mp_uint32 c4spd, mp_sint32* finetune, mp_sint32* relnote);
    mp_uint32 getc4spd(mp_sint32 relnote, mp_sint32 finetune);
    mp_sint32 loadModuleSample(XMFileBase& f, mp_sint32 s, mp_sint32 type1, mp_sint32 type2);
    void setDefaultPanning();
    void postProcessSamples();
    
    enum {
        MODULE_ST3NEWINSTRUMENT = 1,
        MODULE_ST3DUALCOMMANDS = 2,
        MODULE_OLDS3MVOLSLIDES = 4,
        MODULE_ST3NOTECUT = 8,
        ST_PACKING_ADPCM = 1,
        ST_UNSIGNED = 2,
        ST_16BIT = 4
    };
};

class LoaderS3M {
public:
    mp_sint32 load(XMFileBase& f, XModule* module);
    void convertS3MPattern(TXMPattern* pattern, mp_ubyte* data, mp_uint32 numChannels, mp_uint32 patNum);
    mp_ubyte safeRead(mp_ubyte* packed, mp_uint32& index, mp_uint32 size, mp_ubyte def = 0);
};