#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned char byte;
typedef uint32_t word32;
typedef struct WOLFSSH WOLFSSH;
typedef struct WOLFSSH_CTX WOLFSSH_CTX;
typedef struct WOLFSSH_FS WOLFSSH_FS;

#define WS_BAD_ARGUMENT 1
#define WS_BUFFER_E 2
#define WS_MEMORY_E 3
#define WS_FATAL_ERROR 4
#define WS_BAD_FILE_E 5
#define WS_SUCCESS 0
#define WS_SIZE_ONLY 6

#define WOLFSSH_FTP_FAILURE 0
#define WOLFSSH_FTP_OK 1
#define WOLFSSH_FTP_RMDIR 2
#define WS_LOG_SFTP 0

#define UINT32_SZ 4
#define DYNTYPE_BUFFER 0

#define USE_WINDOWS_API 0

#define WLOG(a, b, ...)
#define WMALLOC(a, b, c) malloc(a)
#define WMEMCPY(a, b, c) memcpy(a, b, c)
#define WFREE(a, b, c) free(a)
#define WRMDIR(a, b) rmdir(b)
#define WS_RemoveDirectoryA(a, b) (0)

void ato32(const byte* data, word32* sz);
int wolfSSH_CleanPath(WOLFSSH* ssh, char* path);
int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, byte type, int reqId, char* msg, const char* lang, byte* out, word32* outSz);
void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);