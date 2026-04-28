#include <stdint.h>
#include <stddef.h>

typedef unsigned char byte;
typedef uint32_t word32;

#define WS_SUCCESS 0
#define WS_BAD_ARGUMENT -1
#define WS_BUFFER_E -2
#define WS_MEMORY_E -3
#define WS_FATAL_ERROR -4
#define WS_BAD_FILE_E -5
#define WS_SIZE_ONLY -6

#define UINT32_SZ 4
#define WOLFSSH_FTP_OK 0
#define WOLFSSH_FTP_FAILURE 1

#define DYNTYPE_BUFFER 0

typedef struct WOLFSSH_CTX {
    void* heap;
} WOLFSSH_CTX;

typedef struct WOLFSSH {
    WOLFSSH_CTX* ctx;
} WOLFSSH;

typedef struct WS_SFTP_FILEATRB {
    // Placeholder for file attributes structure
} WS_SFTP_FILEATRB;

#define WS_LOG_SFTP 0

void WLOG(int level, const char* msg);
void ato32(const byte* data, word32* sz);
void* WMALLOC(size_t size, void* heap, int type);
void WMEMCPY(void* dest, const void* src, size_t n);
int wolfSSH_CleanPath(WOLFSSH* ssh, char* path);
int SFTP_ParseAtributes_buffer(WOLFSSH* ssh, WS_SFTP_FILEATRB* atr, byte* data, word32* idx, word32 maxSz);
int SFTP_SetFileAttributes(WOLFSSH* ssh, const char* name, WS_SFTP_FILEATRB* atr);
void WFREE(void* ptr, void* heap, int type);
int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, byte type, int reqId, const char* msg, const char* lang, byte* out, word32* outSz);
void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);