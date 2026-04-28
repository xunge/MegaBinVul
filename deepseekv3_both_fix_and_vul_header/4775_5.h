#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OMX_U32;
typedef int32_t OMX_S32;
typedef void* OMX_HANDLETYPE;
typedef uint8_t* OMX_PTR;
typedef uint32_t OMX_EVENTTYPE;
typedef uint32_t OMX_ERRORTYPE;
typedef uint32_t OMX_COMMANDTYPE;
typedef uint32_t OMX_INDEXTYPE;

typedef struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nSize;
    OMX_U32 nVersion;
    OMX_PTR pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_S32 nTimeStamp;
    OMX_HANDLETYPE hMarkTargetComponent;
    OMX_PTR pMarkData;
    OMX_U32 nOutputPortIndex;
    OMX_PTR pPlatformPrivate;
    OMX_PTR pAppPrivate;
    OMX_PTR pInputPortPrivate;
    OMX_PTR pOutputPortPrivate;
} OMX_BUFFERHEADERTYPE;

enum {
    OMX_EventError,
    OMX_EventPortSettingsChanged,
    OMX_BUFFERFLAG_EOS
};

enum {
    OMX_ErrorUndefined
};

typedef struct {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
} BufferInfo;

typedef struct ogg_ptr {
    void* owner;
} ogg_ptr;

typedef struct ogg_buffer {
    uint8_t* data;
    size_t size;
    int refcount;
    ogg_ptr ptr;
} ogg_buffer;

typedef struct ogg_reference {
    struct ogg_buffer* buffer;
    size_t begin;
    size_t length;
    struct ogg_reference* next;
} ogg_reference;

typedef struct ogg_packet {
    struct ogg_reference* packet;
    long bytes;
    long b_o_s;
    long e_o_s;
    int64_t granulepos;
    int64_t packetno;
} ogg_packet;

typedef struct oggpack_buffer {
    long endbit;
    int endbyte;
    int storage;
    unsigned char *buffer;
    long ptr;
    long end;
} oggpack_buffer;

typedef struct vorbis_info {
    int version;
    int channels;
    long rate;
} vorbis_info;

typedef struct vorbis_dsp_state {
    // DSP state members
} vorbis_dsp_state;

enum {
    NONE,
    AWAITING_DISABLED
};

template <typename T> class List {
public:
    T* begin();
    void erase(T*);
    bool empty();
};

#define CHECK(expr) ((void)0)
#define CHECK_EQ(a, b) ((void)0)
#define CHECK_GE(a, b) ((void)0)
#define ALOGE(...) ((void)0)
#define ALOGV(...) ((void)0)
#define ALOGW(...) ((void)0)
#define android_errorWriteLog(...) ((void)0)

class SoftVorbis {
public:
    void onQueueFilled(OMX_U32 portIndex);
    void notify(OMX_EVENTTYPE, OMX_ERRORTYPE, OMX_U32, OMX_PTR);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    List<BufferInfo*>& getPortQueue(int);
    
    int mOutputPortSettingsChange;
    int mInputBufferCount;
    vorbis_info* mVi;
    vorbis_dsp_state* mState;
    bool mSawInputEos;
    bool mSignalledOutputEos;
    int64_t mAnchorTimeUs;
    int64_t mNumFramesOutput;
    int mNumFramesLeftOnPage;
    static const size_t kMaxNumSamplesPerBuffer;
};

void makeBitReader(const uint8_t*, size_t, ogg_buffer*, ogg_reference*, oggpack_buffer*);
void vorbis_info_init(vorbis_info*);
int vorbis_dsp_init(vorbis_dsp_state*, vorbis_info*);
int _vorbis_unpack_info(vorbis_info*, oggpack_buffer*);
int _vorbis_unpack_books(vorbis_info*, oggpack_buffer*);
int vorbis_dsp_synthesis(vorbis_dsp_state*, ogg_packet*, int);
int vorbis_dsp_pcmout(vorbis_dsp_state*, int16_t*, int);