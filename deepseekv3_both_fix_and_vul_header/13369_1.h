#include <stddef.h>

typedef unsigned char       CPU_BOOLEAN;
typedef unsigned int        CPU_INT32U;
typedef unsigned long       CPU_SIZE_T;
typedef int                 NET_SOCK_ID;
typedef unsigned int        NET_PORT_NBR;
typedef unsigned int        NET_IPv4_ADDR;
typedef char                CPU_CHAR;

typedef enum {
    LIB_MEM_ERR_NONE
} LIB_ERR;

typedef struct {
    void* CertPtr;
    CPU_INT32U CertLen;
    void* KeyPtr;
    CPU_INT32U KeyLen;
} FTPs_SECURE_CFG;

#define DEF_FAIL 0
#define DEF_NULL NULL
#define NET_SOCK_ID_NONE -1
#define NET_SECURE_MODULE_PRESENT
#define FTPs_CFG_FS_PATH_LEN_MAX 256
#define FTPs_NET_BUF_LEN 1024

extern CPU_CHAR* FTPs_FullAbsPathPtr;
extern CPU_CHAR* FTPs_FullRelPathPtr;
extern CPU_CHAR* FTPs_ParentAbsPathPtr;
extern CPU_CHAR* FTPs_CurEntryPtr;
extern CPU_CHAR* FTPs_RenAbsPathPtr;
extern CPU_CHAR* FTPs_RenRelPathPtr;
extern CPU_CHAR* FTPs_NetBufCtrlCmdPtr;
extern CPU_CHAR* FTPs_NetBufCtrlTaskPtr;
extern CPU_CHAR* FTPs_NetBufDtpCmdPtr;
extern CPU_CHAR* FTPs_NetBufSendReplyPtr;
extern NET_IPv4_ADDR FTPs_PublicAddr;
extern NET_PORT_NBR FTPs_PublicPort;
extern FTPs_SECURE_CFG* FTPs_SecureCfgPtr;
extern int FTPs_CtrlTasks;
extern char FTPs_FS_SepChar;

void FTPs_TRACE_DBG(const char*);
void FTPs_TRACE_INFO(const char*);
CPU_INT32U NetFS_CfgPathGetLenMax(void);
char NetFS_CfgPathGetSepChar(void);
CPU_SIZE_T Mem_HeapGetSizeRem(CPU_SIZE_T, LIB_ERR*);
void* Mem_HeapAlloc(CPU_SIZE_T, CPU_SIZE_T, int, LIB_ERR*);
NET_SOCK_ID FTPs_ServerSockInit(void);
CPU_BOOLEAN FTPs_OS_ServerTaskInit(void*);

#define CPU_CRITICAL_ENTER()
#define CPU_CRITICAL_EXIT()
#define CPU_SR_ALLOC()