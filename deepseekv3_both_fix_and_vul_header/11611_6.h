#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

namespace netdutils {
    typedef int Status;
    namespace status {
        const int ok = 0;
    }
    inline Status statusFromErrno(int err, const char*) { return err; }
}

namespace android {
    namespace base {
        class unique_fd {
        public:
            int get() const { return 0; }
        };
    }
}

class Syscall {
public:
    netdutils::Status getsockopt(int fd, int level, int optname, void* optval, socklen_t* optlen) {
        return ::getsockopt(fd, level, optname, optval, optlen) == 0 ? netdutils::status::ok : 
               netdutils::statusFromErrno(errno, "getsockopt failed");
    }
};

class XfrmController {
public:
    netdutils::Status ipSecSetEncapSocketOwner(const android::base::unique_fd& socket, int newUid, uid_t callerUid);
    Syscall& getSyscallInstance() { static Syscall instance; return instance; }
};

#define ALOGD(...)
#define Fd(x) (x.get())
#define UDP_ENCAP 100
#define UDP_ENCAP_ESPINUDP 1
#define UDP_ENCAP_ESPINUDP_NON_IKE 2