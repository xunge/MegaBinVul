#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

class JackServerSocket {
public:
    int Bind(const char* dir, const char* name, int which);
private:
    int fSocket;
    char fName[108];  // sizeof(sockaddr_un.sun_path)
    bool fPromiscuous;
    int fPromiscuousGid;
};

extern void jack_error(const char* format, ...);
extern void jack_log(const char* format, ...);
extern int jack_promiscuous_perms(int fd, const char* name, int gid);
extern void BuildName(const char* name, char* fName, const char* dir, int which, size_t size, bool promiscuous);