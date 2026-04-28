#include <poll.h>
#include <cstdio>
#include <cstddef>

class SystemCmd {
public:
    void init();
private:
    struct pollfd _pfds[3];
    FILE* _files[2];
    int _childStdin;
};