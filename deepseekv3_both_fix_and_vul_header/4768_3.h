#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define OMX_SPEC_VERSION 0x00000101
#define PORT_INDEX_OUT 1
#define MEM_DEVICE "/dev/pmem_adsp"
#define SECURE_BUFPTR NULL
#define SZ_4K 4096
#define ION_FLAG_CACHED 1

#define OMX_IN
#define OMX_INOUT
#define OMX_OUT

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef void* OMX_PTR;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;

struct pmem {
    int fd;
    OMX_U32 size;
    OMX_U32 offset;
    unsigned char* buffer;
};

struct venc_ion {
    int ion_device_fd;
    struct {
        int fd;
    } fd_ion_data;
    struct {
        int handle;
    } ion_alloc_data;
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nSize;
    struct {
        OMX_U32 nVersion;
    } nVersion;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_PTR pAppPrivate;
    OMX_U32 nOutputPortIndex;
    OMX_U8* pBuffer;
};

struct OMX_QCOM_PLATFORM_PRIVATE_PMEM_INFO {
    uint32_t pmem_fd;
    uint32_t offset;
};

struct OutPortDef {
    OMX_U32 nBufferSize;
    OMX_U32 nBufferCountActual;
};

#define OMX_ErrorNone 0
#define OMX_ErrorBadParameter 1
#define OMX_ErrorInsufficientResources 2

#define DEBUG_PRINT_HIGH(...)
#define DEBUG_PRINT_ERROR(...) 
#define DEBUG_PRINT_LOW(...)

#define BITMASK_ABSENT(x, y) 0
#define BITMASK_SET(x, y)

class omx_video {
public:
    static bool output_use_buffer;
    static bool m_use_output_pmem;
    static bool secure_session;
    static struct OMX_BUFFERHEADERTYPE* m_out_mem_ptr;
    static struct pmem* m_pOutput_pmem;
    static struct venc_ion* m_pOutput_ion;
    static struct OutPortDef m_sOutPortDef;
    static unsigned m_out_bm_count;

    OMX_ERRORTYPE use_output_buffer(
        OMX_IN OMX_HANDLETYPE hComp,
        OMX_INOUT OMX_BUFFERHEADERTYPE** bufferHdr,
        OMX_IN OMX_U32 port,
        OMX_IN OMX_PTR appData,
        OMX_IN OMX_U32 bytes,
        OMX_IN OMX_U8* buffer);
};

bool omx_video::output_use_buffer = false;
bool omx_video::m_use_output_pmem = false;
bool omx_video::secure_session = false;
struct OMX_BUFFERHEADERTYPE* omx_video::m_out_mem_ptr = NULL;
struct pmem* omx_video::m_pOutput_pmem = NULL;
struct venc_ion* omx_video::m_pOutput_ion = NULL;
struct OutPortDef omx_video::m_sOutPortDef;
unsigned omx_video::m_out_bm_count = 0;

static int alloc_map_ion_memory(int size, void* alloc_data, void* fd_data, int flags) { return -1; }
static void free_ion_memory(void* ion) {}
static bool dev_use_buf(struct pmem* pmem, int port, int index) { return false; }