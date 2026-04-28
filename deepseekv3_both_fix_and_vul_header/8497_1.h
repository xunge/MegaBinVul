#include <sys/types.h>
#include <sys/wait.h>
#include <sys/poll.h>
#include <unistd.h>
#include <stdio.h>
#include <sstream>

#define y2deb(x)
#define SYSCALL_FAILED_NOTHROW(x)
#define ST_MAYBE_THROW(x, y)
#define SHELL_RET_COMMAND_NOT_EXECUTABLE 126
#define SHELL_RET_COMMAND_NOT_FOUND 127
#define SHELL_RET_SIGNAL 128

enum { IDX_STDOUT, IDX_STDERR };

struct pollfd _pfds[3];
bool _combineOutput;
pid_t _cmdPid;
FILE* _files[2];
FILE* _childStdin;
class OutputProcessor* _outputProc;
bool _doThrow;

class SystemCmd;

class SystemCmdException {
public:
    SystemCmdException(SystemCmd* cmd, const char* msg);
};

class CommandNotFoundException {
public:
    CommandNotFoundException(SystemCmd* cmd);
};

class OutputProcessor {
public:
    void finish();
};

class SystemCmd {
public:
    void sendStdin();
    void checkOutput();
    bool doWait(bool hang, int& cmdRet_ret);
};