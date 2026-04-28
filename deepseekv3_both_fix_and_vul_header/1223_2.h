#include <set>
#include <string>
#include <map>
#include <stdexcept>
#include <mutex>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/stat.h>

using std::set;
using std::string;
using std::map;
using std::runtime_error;
using std::lock_guard;
using std::recursive_mutex;

struct SocketEndpoint {
    string name() const { return ""; }
};

class PipeSocketHandler {
public:
    set<int> listen(const SocketEndpoint& endpoint);
};

#define FATAL_FAIL(x) if ((x) < 0) throw runtime_error("Fatal error")

void initServerSocket(int fd);

extern recursive_mutex globalMutex;
extern map<string, set<int>> pipeServerSockets;