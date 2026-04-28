#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef unsigned char byte;
typedef uint32_t word32;
typedef struct WOLFSSH WOLFSSH;
typedef struct WOLFSSH_CTX WOLFSSH_CTX;
typedef struct WOLFSSH_FS WOLFSSH_FS;

#define WS_BAD_ARGUMENT (-1)
#define WS_BUFFER_E (-2)
#define WS_MEMORY_E (-3)
#define WS_FATAL_ERROR (-4)
#define WS_BAD_FILE_E (-5)
#define WS_SUCCESS (0)
#define WS_SIZE_ONLY (1)

#define UINT32_SZ (4)
#define WOLFSSH_FTP_MKDIR (0)
#define WOLFSSH_FTP_FAILURE (1)
#define WOLFSSH_FTP_OK (0)

#define DYNTYPE_BUFFER (0)

#define USE_WINDOWS_API (0)

#define WS_LOG_SFTP (0)

#define WMALLOC(size, heap, type) malloc(size)
#define WFREE(ptr, heap, type) free(ptr)
#define WMEMCPY(dest, src, size) memcpy(dest, src, size)
#define WMKDIR(fs, path, mode) mkdir(path, mode)
#define WS_CreateDirectoryA(path, heap) CreateDirectoryA(path, NULL)

static inline void ato32(const byte* data, word32* val) {
    *val = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
}

void WLOG(int level, const char* msg, ...);
int wolfSSH_CleanPath(WOLFSSH* ssh, char* path);
int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, byte type, int reqId, const char* msg, const char* lang, byte* out, word32* outSz);
void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);