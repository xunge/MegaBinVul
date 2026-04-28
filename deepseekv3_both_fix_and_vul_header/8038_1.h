#include <stdint.h>

namespace base {
typedef int32_t ProcessId;
}

namespace IPC {
struct ChannelHandle {
    ChannelHandle() {}
    ChannelHandle(const ChannelHandle&) {}
};
}

struct PpapiHostMsg_ChannelCreated {
    PpapiHostMsg_ChannelCreated(const IPC::ChannelHandle&) {}
};

struct PluginEntryPoints {
    void* get_interface;
};

class PpapiThread {
protected:
    PluginEntryPoints plugin_entry_points_;
    bool SetupChannel(base::ProcessId, int, bool, IPC::ChannelHandle*);
    bool SetupRendererChannel(base::ProcessId, int, bool, IPC::ChannelHandle*);
    void Send(PpapiHostMsg_ChannelCreated*);
public:
    void OnCreateChannel(base::ProcessId, int, bool);
};