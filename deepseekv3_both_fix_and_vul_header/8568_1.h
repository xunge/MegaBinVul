#include <unistd.h>
#include <errno.h>
#include <string.h>

#define CMD_BUF_SIZE 1024
#define SLOGE(...)
#define SLOGW(...)

class SocketClient {
public:
    int getSocket();
    void sendMsg(int code, const char* msg, bool addErrno);
};

class FrameworkListener {
public:
    bool onDataAvailable(SocketClient *c);
private:
    bool mSkipToNextNullByte;
    void dispatchCommand(SocketClient* c, char* cmd);
};

void android_errorWriteLog(unsigned, const char*);