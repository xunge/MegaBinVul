#include <signal.h>
#include <stdlib.h>
#include <memory>
#include <string>
#include <iostream>

#define GOOGLE_PROTOBUF_VERIFY_VERSION
#define LOG(level) std::cout
#define INFO 0

using std::shared_ptr;
using std::string;

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
void reconfigureLogger(const char*, const Configurations&);
}  // namespace Loggers
}  // namespace el

namespace et {
void HandleTerminate();
void InterruptSignalHandler(int);
class LogHandler {
public:
    static el::Configurations setupLogHandler(int*, char***);
    static void setupLogFiles(el::Configurations*, const string&, const string&, bool, bool);
    static void setupLogFile(el::Configurations*, const string&, const string&);
    static void stderrToFile(const string&);
};
}  // namespace et

class SocketHandler {};
class PipeSocketHandler : public SocketHandler {};
class SocketEndpoint {
public:
    void set_name(const string&);
};
class HtmServer {
public:
    HtmServer(shared_ptr<SocketHandler>, const SocketEndpoint&);
    void run();
    static string getPipeName();
};

string GetTempDirectory();

using LogHandler = et::LogHandler;