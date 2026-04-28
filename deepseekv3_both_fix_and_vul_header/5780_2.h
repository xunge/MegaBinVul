#include <memory>
#include <vector>
#include <cassert>

namespace base {
class Closure {
public:
    bool is_null() const;
    void Run() const;
};
}  // namespace base

class GpuChannel {
public:
    bool IsLost() const;
    void DestroyChannel();
};

class BrowserGpuChannelHostFactory {
public:
    enum CauseForGpuLaunch {};
    void EstablishGpuChannel(CauseForGpuLaunch cause_for_gpu_launch, const base::Closure& callback);

protected:
    struct EstablishRequest {
        static std::shared_ptr<EstablishRequest> Create(CauseForGpuLaunch cause, int client_id, int host_id);
    };

    std::shared_ptr<EstablishRequest> pending_request_;
    std::shared_ptr<GpuChannel> gpu_channel_;
    std::vector<base::Closure> established_callbacks_;
    int gpu_client_id_;
    int gpu_host_id_;
};

#define DCHECK(condition) assert(condition)