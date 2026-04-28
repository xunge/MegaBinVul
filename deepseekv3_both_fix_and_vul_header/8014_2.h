#include <stdint.h>
#include <cstddef>

#define OMX_SPEC_VERSION 0x00000101
#define PORT_INDEX_OUT 0
#define OMX_COMPONENT_GENERATE_FTB 0
#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_ERROR(...)

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef uint32_t OMX_U32;

typedef struct OMX_VERSIONTYPE {
    OMX_U32 nVersion;
} OMX_VERSIONTYPE;

typedef struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nOutputPortIndex;
    void* pBuffer;
} OMX_BUFFERHEADERTYPE;

typedef struct OMX_PARAM_PORTDEFINITIONTYPE {
    OMX_U32 bEnabled;
} OMX_PARAM_PORTDEFINITIONTYPE;

enum OMX_STATETYPE {
    OMX_StateInvalid,
    OMX_StateIdle,
    OMX_StateExecuting,
    OMX_StatePause
};

#define OMX_IN
#define OMX_ErrorNone 0
#define OMX_ErrorInvalidState 1
#define OMX_ErrorBadParameter 2
#define OMX_ErrorVersionMismatch 3
#define OMX_ErrorBadPortIndex 4
#define OMX_ErrorIncorrectStateOperation 5

class omx_video {
public:
    OMX_STATETYPE m_state;
    OMX_PARAM_PORTDEFINITIONTYPE m_sOutPortDef;
    void post_event(unsigned long, unsigned long, int);
    OMX_ERRORTYPE fill_this_buffer(OMX_IN OMX_HANDLETYPE hComp, OMX_IN OMX_BUFFERHEADERTYPE* buffer);
};