#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t UINT;
typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t HRESULT;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int BOOL;
typedef uint32_t ULONG;

#define TRUE 1
#define FALSE 0
#define FILECONTENTS_SIZE 0x00000001
#define FILECONTENTS_RANGE 0x00000002
#define CFSTR_FILECONTENTS "FileContents"
#define TYMED_ISTREAM 4
#define STREAM_SEEK_SET 0
#define STATFLAG_NONAME 1
#define DATADIR_GET 1
#define CHANNEL_RC_OK 0
#define ERROR_INTERNAL_ERROR 1359
#define TAG "clipboard"
#define S_OK 0
#define SUCCEEDED(hr) ((hr) >= 0)
#define FAILED(hr) ((hr) < 0)

typedef struct _CLIPRDR_FILE_CONTENTS_REQUEST {
    UINT32 streamId;
    UINT32 listIndex;
    UINT32 dwFlags;
    UINT32 nPositionLow;
    UINT32 nPositionHigh;
    UINT32 cbRequested;
} CLIPRDR_FILE_CONTENTS_REQUEST;

typedef struct _CliprdrClientContext {
    void* custom;
} CliprdrClientContext;

typedef struct _wfClipboard {
    UINT32 nFiles;
    char** file_names;
    struct {
        UINT32 nFileSizeLow;
        UINT32 nFileSizeHigh;
    }** fileDescriptor;
} wfClipboard;

typedef struct _FORMATETC {
    uint32_t cfFormat;
    uint32_t dwAspect;
    int32_t lindex;
    uint32_t tymed;
    void* ptd;
} FORMATETC;

typedef struct _STGMEDIUM {
    void* pstm;
} STGMEDIUM;

typedef struct _STATSTG {
    struct {
        uint32_t LowPart;
        uint32_t HighPart;
    } cbSize;
} STATSTG;

typedef struct {
    int32_t LowPart;
    int32_t HighPart;
} LARGE_INTEGER;

typedef struct {
    uint32_t LowPart;
    uint32_t HighPart;
} ULARGE_INTEGER;

typedef void* LPDATAOBJECT;
typedef void* LPSTREAM;
typedef void* LPENUMFORMATETC;
typedef void* PULONG;

static HRESULT OleGetClipboard(LPDATAOBJECT* ppDataObj) { return S_OK; }
static uint32_t RegisterClipboardFormat(const char* lpszFormat) { return 0; }
static void IStream_Release(LPSTREAM pStream) {}
static HRESULT IDataObject_EnumFormatEtc(LPDATAOBJECT pDataObj, int dwDirection, LPENUMFORMATETC* ppEnumFormatEtc) { return S_OK; }
static HRESULT IEnumFORMATETC_Next(LPENUMFORMATETC pEnumFormatEtc, ULONG celt, FORMATETC* rgelt, ULONG* pceltFetched) { return S_OK; }
static HRESULT IDataObject_GetData(LPDATAOBJECT pDataObj, FORMATETC* pFormatEtc, STGMEDIUM* pMedium) { return S_OK; }
static HRESULT IStream_Stat(LPSTREAM pStream, STATSTG* pStatstg, uint32_t grfStatFlag) { return S_OK; }
static HRESULT IStream_Seek(LPSTREAM pStream, LARGE_INTEGER dlibMove, uint32_t dwOrigin, ULARGE_INTEGER* plibNewPosition) { return S_OK; }
static HRESULT IStream_Read(LPSTREAM pStream, void* pv, ULONG cb, ULONG* pcbRead) { return S_OK; }
static void IDataObject_Release(LPDATAOBJECT pDataObj) {}
static BOOL wf_cliprdr_get_file_contents(const char* filename, BYTE* pData, UINT32 nPositionLow, UINT32 nPositionHigh, UINT32 cbRequested, DWORD* uSize) { return TRUE; }
static UINT cliprdr_send_response_filecontents(wfClipboard* clipboard, UINT32 streamId, UINT32 uSize, BYTE* pData) { return CHANNEL_RC_OK; }
static void WLog_ERR(const char* tag, const char* message) {}

#define ZeroMemory(ptr, size) memset(ptr, 0, size)