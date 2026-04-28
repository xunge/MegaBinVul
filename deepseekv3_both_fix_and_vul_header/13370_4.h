#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>

typedef uint8_t     CPU_INT08U;
typedef uint16_t    CPU_INT16U;
typedef uint32_t    CPU_INT32U;
typedef int16_t     CPU_INT16S;
typedef int32_t     CPU_INT32S;
typedef char        CPU_CHAR;
typedef uint8_t     CPU_BOOLEAN;

#define DEF_OK      1
#define DEF_FAIL    0
#define DEF_YES     1
#define DEF_NO      0

#define NET_IPv4_ADDR_ANY 0
#define NET_UTIL_HOST_TO_NET_32 htonl
#define NET_UTIL_HOST_TO_NET_16 htons

typedef enum {
    NET_FS_FILE_MODE_OPEN,
    NET_FS_FILE_MODE_CREATE
} NET_FS_FILE_MODE;

typedef enum {
    NET_FS_FILE_ACCESS_RD,
    NET_FS_FILE_ACCESS_WR,
    NET_FS_FILE_ACCESS_RDWR
} NET_FS_FILE_ACCESS;

typedef struct {
    CPU_INT16U Yr;
    CPU_INT08U Month;
    CPU_INT08U Day;
    CPU_INT08U Hr;
    CPU_INT08U Min;
    CPU_INT08U Sec;
} NET_FS_DATE_TIME;

typedef struct {
    CPU_INT32U          Size;
    NET_FS_DATE_TIME    DateTimeCreate;
} NET_FS_ENTRY;

typedef uint32_t NET_IPv4_ADDR;
typedef uint16_t NET_PORT_NBR;
typedef int NET_ERR;

typedef enum {
    FTP_CMD_NOOP,
    FTP_CMD_QUIT,
    FTP_CMD_REIN,
    FTP_CMD_SYST,
    FTP_CMD_FEAT,
    FTP_CMD_HELP,
    FTP_CMD_USER,
    FTP_CMD_PASS,
    FTP_CMD_MODE,
    FTP_CMD_TYPE,
    FTP_CMD_STRU,
    FTP_CMD_PASV,
    FTP_CMD_PORT,
    FTP_CMD_REST,
    FTP_CMD_PWD,
    FTP_CMD_CWD,
    FTP_CMD_CDUP,
    FTP_CMD_MKD,
    FTP_CMD_RMD,
    FTP_CMD_NLST,
    FTP_CMD_LIST,
    FTP_CMD_RETR,
    FTP_CMD_STOR,
    FTP_CMD_APPE,
    FTP_CMD_DELE,
    FTP_CMD_RNFR,
    FTP_CMD_RNTO,
    FTP_CMD_SIZE,
    FTP_CMD_MDTM,
    FTP_CMD_PBSZ,
    FTP_CMD_PROT
} FTP_CMD;

typedef enum {
    FTP_MODE_STREAM,
    FTP_MODE_BLOCK,
    FTP_MODE_COMPRESSED
} FTP_MODE;

typedef enum {
    FTP_TYPE_ASCII,
    FTP_TYPE_IMAGE,
    FTP_TYPE_LOCAL,
    FTP_TYPE_EBCDIC
} FTP_TYPE;

typedef enum {
    FTP_FORM_NONPRINT = 1,
    FTP_FORM_TELNET,
    FTP_FORM_CARGCTRL
} FTP_FORM;

typedef enum {
    FTP_STRU_FILE,
    FTP_STRU_RECORD,
    FTP_STRU_PAGE
} FTP_STRU;

typedef enum {
    FTP_REPLY_OKAY,
    FTP_REPLY_SERVERCLOSING,
    FTP_REPLY_SYSTEMTYPE,
    FTP_REPLY_SYSTEMSTATUS,
    FTP_REPLY_HELPMESSAGE,
    FTP_REPLY_NEEDPASSWORD,
    FTP_REPLY_PARMSYNTAXERR,
    FTP_REPLY_LOGGEDIN,
    FTP_REPLY_NOTLOGGEDIN,
    FTP_REPLY_PARMNOSUPPORT,
    FTP_REPLY_ENTERPASVMODE,
    FTP_REPLY_CANTOPENDATA,
    FTP_REPLY_NEEDMOREINFO,
    FTP_REPLY_PATHNAME,
    FTP_REPLY_ACTIONCOMPLETE,
    FTP_REPLY_OKAYOPENING,
    FTP_REPLY_NOTFOUND,
    FTP_REPLY_NAMEERR,
    FTP_REPLY_FILESTATUS,
    FTP_REPLY_PBSZ,
    FTP_REPLY_PROT,
    FTP_REPLY_CMDNOSUPPORT
} FTP_REPLY;

typedef enum {
    FTPs_STATE_LOGOUT,
    FTPs_STATE_GOTUSER,
    FTPs_STATE_LOGIN,
    FTPs_STATE_GOTREST,
    FTPs_STATE_GOTRNFR
} FTPs_STATE;

typedef struct {
    NET_IPv4_ADDR Addr;
    NET_PORT_NBR  Port;
} FTPs_SOCK_ADDR;

typedef struct {
    CPU_INT32U      CtrlSockID;
    FTP_CMD         CtrlCmd;
    CPU_CHAR       *CtrlCmdArgs;
    FTPs_STATE      CtrlState;
    FTP_MODE        DtpMode;
    FTP_TYPE        DtpType;
    FTP_FORM        DtpForm;
    FTP_STRU        DtpStru;
    FTP_CMD         DtpCmd;
    CPU_INT32U      DtpOffset;
    CPU_BOOLEAN     DtpPasv;
    FTPs_SOCK_ADDR  DtpSockAddr;
    CPU_CHAR        User[32];
    CPU_CHAR        Pass[32];
    CPU_CHAR        BasePath[256];
    CPU_CHAR        RelPath[256];
    CPU_CHAR        CurEntry[256];
} FTPs_SESSION_STRUCT;

typedef struct {
    const char *ReplyStr;
} FTPs_REPLY_STRUCT;

#define CPU_SR_ALLOC()
#define CPU_CRITICAL_ENTER()
#define CPU_CRITICAL_EXIT()

extern NET_IPv4_ADDR FTPs_PublicAddr;
extern NET_PORT_NBR FTPs_PublicPort;
extern CPU_CHAR *FTPs_NetBufCtrlCmdPtr;
extern CPU_CHAR *FTPs_FullAbsPathPtr;
extern CPU_CHAR *FTPs_FullRelPathPtr;
extern CPU_CHAR *FTPs_ParentAbsPathPtr;
extern CPU_CHAR *FTPs_CurEntryPtr;
extern CPU_CHAR *FTPs_RenAbsPathPtr;
extern CPU_CHAR *FTPs_RenRelPathPtr;
extern FTPs_REPLY_STRUCT FTPs_Reply[];
extern CPU_INT32U FTPs_NET_BUF_LEN;
extern CPU_INT32U FTPs_CFG_FS_PATH_LEN_MAX;

extern void FTPs_SendReply(CPU_INT32U sock_id, FTP_REPLY reply, CPU_CHAR *msg);
extern void FTPs_StopPasvMode(FTPs_SESSION_STRUCT *ftp_session);
extern CPU_CHAR *FTPs_FindArg(CPU_CHAR **args);
extern CPU_CHAR *FTPs_FindFileName(CPU_CHAR **args);
extern void FTPs_ToFTPStylePath(CPU_CHAR *path);
extern void FTPs_ToFSStylePath(CPU_CHAR *path);
extern CPU_BOOLEAN FTPs_AuthUser(FTPs_SESSION_STRUCT *ftp_session);
extern CPU_BOOLEAN FTPs_BuildPath(CPU_CHAR *full_abs_path, CPU_INT32U full_abs_path_len,
                                 CPU_CHAR *full_rel_path, CPU_INT32U full_rel_path_len,
                                 CPU_CHAR *parent_abs_path, CPU_INT32U parent_abs_path_len,
                                 CPU_CHAR *cur_entry, CPU_INT32U cur_entry_len,
                                 CPU_CHAR *base_path, CPU_CHAR *rel_path, CPU_CHAR *entry);
extern void FTPs_StartPasvMode(FTPs_SESSION_STRUCT *ftp_session, NET_ERR *net_err);
extern void FTPs_DtpTask(void *arg);

extern CPU_INT32U Str_Copy_N(CPU_CHAR *dest, const CPU_CHAR *src, CPU_INT32U max_len);
extern CPU_INT32U Str_Len(const CPU_CHAR *str);
extern CPU_INT16S Str_Cmp(const CPU_CHAR *str1, const CPU_CHAR *str2);
extern CPU_INT32U Str_ParseNbr_Int32U(const CPU_CHAR *str, CPU_CHAR **end_ptr, CPU_INT08U base);
extern CPU_BOOLEAN ASCII_IsDig(CPU_CHAR c);
extern void Str_FmtPrint(char *buf, CPU_INT32U buf_len, const char *fmt, ...);
extern void Str_FmtScan(const char *buf, const char *fmt, ...);

extern void *NetFS_DirOpen(const CPU_CHAR *path);
extern void NetFS_DirClose(void *p_dir);
extern void *NetFS_FileOpen(const CPU_CHAR *path, NET_FS_FILE_MODE mode, NET_FS_FILE_ACCESS access);
extern void NetFS_FileClose(void *p_file);
extern CPU_INT32U NetFS_FileSizeGet(void *p_file, CPU_INT32U *p_size);
extern CPU_INT32U NetFS_FileDateTimeCreateGet(void *p_file, NET_FS_DATE_TIME *p_date_time);
extern CPU_INT32U NetFS_EntryCreate(const CPU_CHAR *path, CPU_BOOLEAN is_dir);
extern CPU_INT32U NetFS_EntryDel(const CPU_CHAR *path, CPU_BOOLEAN is_file);
extern CPU_INT32U NetFS_EntryRename(const CPU_CHAR *path_old, const CPU_CHAR *path_new);
extern CPU_INT32U NetFS_EntryTimeSet(const CPU_CHAR *path, const NET_FS_DATE_TIME *p_date_time);
extern CPU_INT32U NetFS_CfgPathGetLenMax(void);