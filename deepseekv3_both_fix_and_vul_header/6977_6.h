#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <memory>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include <sys/types.h>

#define GOOGLE_PROTOBUF_VERIFY_VERSION
#define INFO 0

using namespace std;

struct termios terminal_backup;

void term(int signum) {}

namespace cxxopts {
    class OptionAdder {
    public:
        OptionAdder& operator()(const string&, const string&);
    };
    class ParseResult {
    public:
        size_t count(const string&);
    };
    class Options {
    public:
        Options(const string&, const string&);
        void allow_unrecognised_options();
        OptionAdder add_options();
        ParseResult parse(int, char**);
        string help(const vector<string>&);
    };
}

namespace el {
    class Configurations {
    public:
        void setGlobally(int, const string&);
    };
    namespace ConfigurationType {
        const int ToStandardOutput = 0;
    }
    namespace Loggers {
        void setVerboseLevel(int);
        void reconfigureLogger(const string&, const Configurations&);
    }
}

namespace LogHandler {
    el::Configurations setupLogHandler(int*, char***);
    void setupLogFiles(el::Configurations*, const string&, const string&, bool, bool);
    void setupLogFile(el::Configurations*, const string&, const string&);
    void stderrToFile(const string&);
}

namespace et {
    void HandleTerminate();
    void InterruptSignalHandler(int);
}

namespace DaemonCreator {
    const int CHILD = 0;
    int create(bool, const string&);
}

class SocketHandler {
public:
    virtual ~SocketHandler() = default;
};

class PipeSocketHandler : public SocketHandler {
public:
    PipeSocketHandler();
};

class SocketEndpoint {
public:
    void set_name(const string&);
};

class HtmServer {
public:
    static string getPipeName();
};

class HtmClient {
public:
    HtmClient(shared_ptr<SocketHandler>, SocketEndpoint);
    void run();
};

class RawSocketUtils {
public:
    static void writeAll(int, const char*, size_t);
};

string SystemToStr(const char* command);
string GetTempDirectory();

#define CLOG(level, stream) cout
#define LOG(level) cout