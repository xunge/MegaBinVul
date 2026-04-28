#include <arpa/inet.h>
#include <algorithm>
#include <cerrno>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>

typedef uint32_t klinux_in_addr;
typedef uint8_t klinux_in6_addr[16];

namespace asylo {
namespace host_call {
constexpr int kInetPtonHandler = 0;
}  // namespace host_call
namespace primitives {
class TrustedPrimitives {
public:
    static void BestEffortAbort(const char* message) {
        abort();
    }
};
}  // namespace primitives
}  // namespace asylo

extern "C" {
int FromkLinuxErrorNumber(int klinux_errno);
int TokLinuxAfFamily(int af);
}

class MessageWriter {
public:
    template <typename T> void Push(T value);
    void PushByReference(const struct Extent &extent);
};

class MessageReader {
public:
    template <typename T> T next();
    Extent next();
    const Extent& get_buffer() const;
};

struct Extent {
    const void* buffer;
    size_t length;
    size_t size() const { return length; }
    const void* data() const { return buffer; }
};

int NonSystemCallDispatcher(int handler, MessageWriter* input, MessageReader* output);
void CheckStatusAndParamCount(int status, MessageReader& output, const char* function_name, int param_count);