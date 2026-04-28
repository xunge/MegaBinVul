#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
#define WOLFSSH_FTP_STAT 1
#define WOLFSSH_FTP_FAILURE 2
#define WOLFSSH_FTP_ATTRS 3
#define WOLFSSH_SFTP_HEADER 5
#define WS_LOG_SFTP 6
#define DYNTYPE_BUFFER 1

#define WMALLOC(size, heap, type) malloc(size)
#define WFREE(ptr, heap, type) free(ptr)
#define WMEMCPY(dest, src, n) memcpy(dest, src, n)
#define WMEMSET(dest, val, n) memset(dest, val, n)

typedef struct {
    void* heap;
} WOLFSSH_CTX;

typedef struct {
    WOLFSSH_CTX* ctx;
    void* fs;
} WOLFSSH;

typedef struct {
    // Define WS_SFTP_FILEATRB structure members here
} WS_SFTP_FILEATRB;

void ato32(const byte* data, word32* val);
int wolfSSH_CleanPath(WOLFSSH* ssh, char* path);
int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, int type, int reqId, const char* msg, const char* lang, byte* out, word32* outSz);
int SFTP_GetAttributes(void* fs, const char* name, WS_SFTP_FILEATRB* atr, int flags, void* heap);
word32 SFTP_AtributesSz(WOLFSSH* ssh, WS_SFTP_FILEATRB* atr);
int SFTP_SetHeader(WOLFSSH* ssh, int reqId, int type, word32 sz, byte* out);
void SFTP_SetAttributes(WOLFSSH* ssh, byte* out, word32 sz, WS_SFTP_FILEATRB* atr);
void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);
void WLOG(int level, const char* msg);