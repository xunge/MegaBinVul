#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

#define MSG_REVISION 1
#define MSG_ATTACH 1
#define MSG_WINCH 2
#define MSG_CREATE 3
#define MSG_CONT 4
#define MSG_ERROR 5
#define MSG_HANGUP 6
#define MSG_QUERY 7
#define MSG_COMMAND 8
#define SIG_BYE 9

struct msg {
    int protocol_revision;
    int type;
    char m_tty[32];
    union {
        struct {
            int apid;
        } attach;
        struct {
            char duser[32];
        } detach;
        struct {
            char writeback[1024];
            int apid;
        } command;
        char message[1024];
    } m;
};

struct win {
    char w_tty[32];
    struct win *w_next;
    struct {
        struct {
            struct display *c_display;
        } *l_cvlist;
    } w_layer;
};

struct acluser {
    char *u_password;
};

struct display {
    char D_usertty[32];
    int D_userpid;
    struct acluser *D_user;
    int D_status;
    int D_tcinited;
    int D_blocked;
    struct display *d_next;
};

struct serv_read {
    int fd;
};

extern int ServerSocket;
extern char *SockPath;
extern struct display *displays;
extern struct win *windows;
extern struct display *display;
extern struct serv_read serv_read;
extern int queryflag;

#define D_usertty (display->D_usertty)
#define D_userpid (display->D_userpid)
#define D_user (display->D_user)
#define D_status (display->D_status)
#define D_tcinited (display->D_tcinited)
#define D_blocked (display->D_blocked)

int IsSocket(const char *path);
void debug(const char *fmt, ...);
void Panic(int err, const char *fmt, ...);
void Msg(int err, const char *fmt, ...);
int secopen(const char *path, int flags, int mode);
void evdeq(struct serv_read *sr);
void evenq(struct serv_read *sr);
void debug2(const char *fmt, ...);
int TTYCMP(const char *a, const char *b);
void RemoveStatus(void);
void CheckScreenSize(int flag);
void ExecCreate(struct msg *m);
int CreateTempDisplay(struct msg *m, int fd, struct win *wi);
void FinishAttach(struct msg *m);
void Hangup(void);
void FinishDetach(struct msg *m);
char *SaveStr(const char *s);
int MakeClientSocket(int fd, bool is_socket);
void Free(void *ptr);
void DoCommandMsg(struct msg *m);
void Kill(int pid, int sig);