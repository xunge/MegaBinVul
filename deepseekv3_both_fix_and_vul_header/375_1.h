#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

class JackClientSocket {
public:
    int Connect(const char* dir, const char* name, int which);
private:
    int fSocket;
    bool fPromiscuous;
};

extern void jack_error(const char* format, ...);
extern void jack_log(const char* format, ...);
extern void BuildName(const char* name, char* path, const char* dir, int which, size_t size, bool promiscuous);