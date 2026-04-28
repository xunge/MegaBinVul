#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <algorithm>
#include <cstdint>
#include <cstddef>

class Extent {
public:
    size_t size();
    template<typename T> T* As();
};

class MessageWriter {
public:
    void Push(int value);
    template<typename T> void Push(T value);
};

class MessageReader {
public:
    Extent next();
    template<typename T> T next();
};

namespace asylo {
namespace host_call {
const int kRecvMsgHandler = 0;
}
namespace primitives {
class TrustedPrimitives {
public:
    static void BestEffortAbort(const char* message);
};
}
}

size_t CalculateTotalMessageSize(struct msghdr *msg);
int FromkLinuxErrorNumber(int klinux_errno);
void CheckStatusAndParamCount(int status, MessageReader &output, const char *func_name, int param_count, bool match_exact_params);
int NonSystemCallDispatcher(int handler, MessageWriter *input, MessageReader *output);