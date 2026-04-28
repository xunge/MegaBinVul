#include <arpa/inet.h>
#include <algorithm>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <vector>

struct MessageWriter {
    template<typename T> void Push(T);
    void PushByReference(struct Extent);
    void Push(socklen_t);
};

struct MessageReader {
    std::vector<char> next();
    template<typename T> T next();
};

struct Extent {
    const char* data;
    size_t size;
};

int TokLinuxAfFamily(int);
int FromkLinuxErrorNumber(int);
void CheckStatusAndParamCount(int, MessageReader&, const char*, int);
int NonSystemCallDispatcher(int, MessageWriter*, MessageReader*);

namespace asylo {
namespace host_call {
constexpr int kInetNtopHandler = 0;
}  // namespace host_call
}  // namespace asylo