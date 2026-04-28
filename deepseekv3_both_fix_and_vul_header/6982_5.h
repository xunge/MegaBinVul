#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <memory>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

struct termios terminal_backup;

void term(int signum) {}

string SystemToStr(const char* command) { return ""; }

string GetTempDirectory() { return ""; }

#define GOOGLE_PROTOBUF_VERIFY_VERSION
#define LOG(level) cout
#define CLOG(level, stream) cout
#define INFO 0

namespace cxxopts {
    class Options {
    public:
        Options(const char*, const char*) {}
        void allow_unrecognised_options() {}
        auto& add_options() { return *this; }
        auto& operator()(const char*, const char*) { return *this; }
        auto parse(int, char**) { return *this; }
        string help(const initializer_list<int>&) { return ""; }
        int count(const char*) { return 0; }
    };
}

namespace el {
    enum ConfigurationType { ToStandardOutput };
    class Configurations {
    public:
        void setGlobally(ConfigurationType, const char*) {}
    };
    class Loggers {
    public:
        static void setVerboseLevel(int) {}
        static void reconfigureLogger(const char*, Configurations) {}
    };
}

namespace LogHandler {
    el::Configurations setupLogHandler(int* argc, char*** argv) { return el::Configurations(); }
    void setupLogFiles(el::Configurations*, string, const char*, bool, bool) {}
    void setupLogFile(el::Configurations*, string, string) {}
    void stderrToFile(string) {}
}

namespace et {
    void HandleTerminate() {}
    void InterruptSignalHandler(int) {}
}

namespace DaemonCreator {
    const int CHILD = 0;
    int create(bool, const char*) { return 0; }
}

class SocketHandler {};
class PipeSocketHandler : public SocketHandler {};
class SocketEndpoint {
public:
    void set_name(string) {}
};
class HtmClient {
public:
    HtmClient(shared_ptr<SocketHandler>, SocketEndpoint) {}
    void run() {}
};
class HtmServer {
public:
    static string getPipeName() { return ""; }
};
class RawSocketUtils {
public:
    static void writeAll(int, const char*, size_t) {}
};