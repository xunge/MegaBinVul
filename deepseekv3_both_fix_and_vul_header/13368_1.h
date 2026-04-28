#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdint.h>

typedef int32_t CPU_INT32S;
typedef uint32_t CPU_INT32U;
typedef int16_t CPU_INT16S;
typedef uint16_t CPU_INT16U;
typedef char CPU_CHAR;
typedef int NET_ERR;
typedef int NET_SOCK_ID;

#define DEF_NULL NULL
#define DEF_TRUE 1
#define DEF_NO 0
#define DEF_OFF 0

#define NET_SOCK_ADDR_FAMILY_IP_V4 0
#define NET_SOCK_FLAG_NONE 0
#define NET_SOCK_ERR_NONE 0
#define NET_SOCK_ERR_RX_Q_EMPTY 1
#define NET_IPv4_ADDR_ANY 0

#define FTP_CMD_NOOP 0
#define FTP_CMD_MAX 0
#define FTP_CMD_QUIT 0
#define FTP_MODE_STREAM 0
#define FTP_TYPE_ASCII 0
#define FTP_FORM_NONPRINT 0
#define FTP_STRU_FILE 0
#define FTP_REPLY_SERVERREADY 0
#define FTP_REPLY_SERVERCLOSING 0
#define FTP_REPLY_CMDNOSUPPORT 0
#define FTP_REPLY_NOTLOGGEDIN 0
#define FTP_REPLY_CMDBADSEQUENCE 0

#define FTPs_STATE_LOGOUT 0
#define FTPs_STATE_LOGIN 0

typedef struct {
    int AddrFamily;
    uint32_t Addr;
    uint16_t Port;
} NET_SOCK_ADDR_STRUCT;

typedef struct {
    NET_SOCK_ADDR_STRUCT DtpSockAddr;
    NET_SOCK_ID CtrlSockID;
    int CtrlState;
    int CtrlCmd;
    CPU_CHAR* CtrlCmdArgs;
    NET_SOCK_ID DtpSockID;
    int DtpPasv;
    int DtpMode;
    int DtpType;
    int DtpForm;
    int DtpStru;
    int DtpCmd;
    CPU_INT32U DtpOffset;
} FTPs_SESSION_STRUCT;

extern CPU_INT32U FTPs_CtrlTasks;
extern CPU_CHAR* FTPs_NetBufCtrlTaskPtr;
extern CPU_INT32U FTPs_NET_BUF_LEN;
extern void* FTPs_SecureCfgPtr;
extern CPU_INT16U FTPs_CFG_DATA_IPPORT_SECURE;
extern CPU_INT16U FTPs_CFG_DATA_IPPORT;
extern CPU_INT32U FTPs_CFG_CTRL_MAX_RX_TIMEOUT_MS;

extern void FTPs_SendReply(NET_SOCK_ID, int, CPU_CHAR*);
extern void FTPs_StopPasvMode(FTPs_SESSION_STRUCT*);
extern void FTPs_TRACE_DBG(const char*, ...);
extern void FTPs_TRACE_INFO(const char*, ...);
extern CPU_CHAR* FTPs_FindArg(CPU_CHAR**);
extern void FTPs_ProcessCtrlCmd(FTPs_SESSION_STRUCT*);
extern void FTPs_OS_TaskDel(void);
extern CPU_INT16S Str_Cmp(CPU_CHAR*, CPU_CHAR*);
extern CPU_CHAR* Str_Char_N(CPU_CHAR*, CPU_INT32S, CPU_CHAR);
extern CPU_CHAR ASCII_ToUpper(CPU_CHAR);
extern void NetSock_CfgTimeoutRxQ_Set(NET_SOCK_ID, CPU_INT32U, NET_ERR*);
extern CPU_INT32S NetSock_RxData(NET_SOCK_ID, CPU_CHAR*, CPU_INT32U, int, NET_ERR*);
extern void NetSock_Close(NET_SOCK_ID, NET_ERR*);

struct {
    int CmdCode;
    CPU_CHAR* CmdStr;
    int* CmdCntxt;
} FTPs_Cmd[1];

#define NET_UTIL_HOST_TO_NET_32(x) htonl(x)
#define NET_UTIL_HOST_TO_NET_16(x) htons(x)