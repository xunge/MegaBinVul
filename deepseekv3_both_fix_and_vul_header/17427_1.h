#include <stdint.h>
#include <stdlib.h>
#include <string.h>
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
#define WOLFSSH_FTP_LSTAT 0
#define WOLFSSH_FTP_FAILURE 0
#define WOLFSSH_FTP_ATTRS 0
#define WOLFSSH_SFTP_HEADER 0
#define WS_LOG_SFTP 0
#define DYNTYPE_BUFFER 0

typedef struct WOLFSSH WOLFSSH;

struct WOLFSSH {
    void* fs;
    struct {
        void* heap;
    }* ctx;
};

typedef struct {
    uint32_t flags;
    uint64_t size;
    uint32_t uid;
    uint32_t gid;
    uint32_t permissions;
    uint32_t atime;
    uint32_t mtime;
} WS_SFTP_FILEATRB;

#define WMALLOC(size, heap, type) malloc(size)
#define WFREE(ptr, heap, type) free(ptr)
#define WMEMCPY(dest, src, size) memcpy(dest, src, size)
#define WMEMSET(dest, val, size) memset(dest, val, size)

void WLOG(int level, const char* msg);
int wolfSSH_CleanPath(WOLFSSH* ssh, char* name);
int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, int type, int reqId, const char* msg, const char* lang, byte* out, word32* outSz);
int SFTP_GetAttributes(void* fs, char* name, WS_SFTP_FILEATRB* atr, int flag, void* heap);
word32 SFTP_AtributesSz(WOLFSSH* ssh, WS_SFTP_FILEATRB* atr);
int SFTP_SetHeader(WOLFSSH* ssh, int reqId, int type, word32 sz, byte* out);
void SFTP_SetAttributes(WOLFSSH* ssh, byte* out, word32 sz, WS_SFTP_FILEATRB* atr);
void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);
void ato32(byte* data, word32* sz);