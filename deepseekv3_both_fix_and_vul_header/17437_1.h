#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned char byte;
typedef uint32_t word32;

#define WOLFSSH_MAX_FILENAME 256
#define UINT32_SZ sizeof(word32)
#define WS_BAD_ARGUMENT (-1)
#define WS_BUFFER_E (-2)
#define WS_FATAL_ERROR (-3)
#define WS_MEMORY_E (-4)
#define WS_BAD_FILE_E (-5)
#define WS_SUCCESS 0
#define WS_SIZE_ONLY 1

#define WOLFSSH_FTP_REALPATH 0
#define WOLFSSH_FTP_FAILURE 0
#define WOLFSSH_FTP_NAME 0
#define WOLFSSH_SFTP_HEADER 0
#define WS_DELIM '/'
#define WS_LOG_SFTP 0
#define DYNTYPE_BUFFER 0

#define WMEMCPY(dst, src, sz) memcpy(dst, src, sz)
#define WMEMSET(dst, val, sz) memset(dst, val, sz)
#define WSTRNCAT(dst, src, sz) strncat(dst, src, sz)
#define XSTRNCPY(dst, src, sz) strncpy(dst, src, sz)
#define WLOG(level, msg, ...)
#define WGETCWD(fs, buf, sz) getcwd(buf, sz)
#define WMALLOC(sz, heap, type) malloc(sz)
#define WFREE(ptr, heap, type) free(ptr)

typedef struct WOLFSSH WOLFSSH;
typedef struct WS_SFTP_FILEATRB WS_SFTP_FILEATRB;

struct WOLFSSH {
    struct {
        void* heap;
    }* ctx;
    char* sftpDefaultPath;
    void* fs;
};

struct WS_SFTP_FILEATRB {
    int dummy;
};

static void ato32(const byte* data, word32* val);
static void c32toa(word32 val, byte* data);
static int wolfSSH_CleanPath(WOLFSSH* ssh, char* path);
static int wolfSSH_SFTP_CreateStatus(WOLFSSH* ssh, int status, int reqId, 
        const char* msg, const char* lang, byte* out, word32* outSz);
static void wolfSSH_SFTP_RecvSetSend(WOLFSSH* ssh, byte* out, word32 outSz);
static byte* wolfSSH_SFTP_RecvGetData(WOLFSSH* ssh);
static word32 SFTP_AtributesSz(WOLFSSH* ssh, WS_SFTP_FILEATRB* atr);
static void SFTP_SetHeader(WOLFSSH* ssh, int reqId, int type, word32 sz, byte* out);
static void SFTP_SetAttributes(WOLFSSH* ssh, byte* out, word32 outSz, WS_SFTP_FILEATRB* atr);