#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <poll.h>

const std::string PRIMARY_SHELL = "/bin/sh";
const std::string ALTERNATE_SHELL = "/bin/bash";

enum { IDX_STDOUT = 0, IDX_STDERR = 1 };

class SystemCmd;

struct SystemCmdException {
    SystemCmdException(SystemCmd* cmd, const std::string& msg) {}
};

class OutputProcessor {
public:
    void reset() {}
};

struct StopWatch {
    friend std::ostream& operator<<(std::ostream& os, const StopWatch& sw) { return os; }
};

class SystemCmd {
public:
    std::string _cmd;
    std::string _lastCmd;
    bool _doThrow;
    bool _testmode;
    bool _combineOutput;
    bool _execInBackground;
    int _cmdPid;
    int _cmdRet;
    FILE* _childStdin;
    FILE* _files[2];
    struct pollfd _pfds[3];
    OutputProcessor* _outputProc;

    void invalidate() {}
    void closeOpenFds() {}
    void doWait(bool, int&) {}
    void checkOutput() {}
    void logOutput() {}
    std::string cmd() const { return _cmd; }
    int doExecute(const std::string& command);
};

#define ST_MAYBE_THROW(exception, flag) if (flag) throw exception
#define SYSCALL_FAILED(msg) 
#define SYSCALL_FAILED_NOTHROW(msg) 
#define y2deb(msg) 
#define y2err(msg) 
#define y2mil(msg) 

using std::string;