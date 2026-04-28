#include <memory>
#include <string>

#define TRACE_EVENT0(category, name)

namespace gpu {
struct GPUInfo {
    void SetGpuInfo(const GPUInfo& info);
};
}

namespace IPC {
struct ChannelHandle {
    struct {
        int fd;
    } socket;
    std::string name;
};
}

enum CauseForGpuLaunch {};

class GpuHostMsg_EstablishGpuChannel {
public:
    GpuHostMsg_EstablishGpuChannel(CauseForGpuLaunch cause, 
                                  int* client_id,
                                  IPC::ChannelHandle* handle,
                                  gpu::GPUInfo* gpu_info);
};

class ContentClient {
public:
    void SetGpuInfo(const gpu::GPUInfo& info);
};

class ChildProcess {
public:
    static ChildProcess* current();
    void* io_message_loop_proxy();
    void* GetShutDownEvent();
};

class GpuChannelHost {
public:
    bool IsLost();
    void DestroyChannel();
    static std::unique_ptr<GpuChannelHost> Create(void* impl,
                                                const gpu::GPUInfo& gpu_info,
                                                const IPC::ChannelHandle& handle,
                                                void* shutdown_event,
                                                void* buffer_manager);
};

class RenderThreadImpl {
public:
    std::unique_ptr<GpuChannelHost> gpu_channel_;
    void* io_message_loop_proxy_;
    void* gpu_memory_buffer_manager();

    bool Send(GpuHostMsg_EstablishGpuChannel* msg);
    ContentClient* GetContentClient();
    GpuChannelHost* EstablishGpuChannelSync(CauseForGpuLaunch cause_for_gpu_launch);
};