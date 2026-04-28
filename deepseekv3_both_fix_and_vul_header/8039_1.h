#include <vector>
#include <queue>
#include <cassert>

#define CHECK_NE(a, b) assert((a) != (b))

namespace base {
typedef int ProcessId;
typedef int ProcessHandle;
const ProcessId kNullProcessId = 0;
const ProcessHandle kNullProcessHandle = 0;
ProcessId GetProcId(ProcessHandle handle);
}  // namespace base

namespace IPC {
struct ChannelHandle {
};
}  // namespace IPC

class PpapiMsg_CreateChannel {
public:
    PpapiMsg_CreateChannel(base::ProcessId process_id, int renderer_child_id, bool off_the_record);
    void set_unblock(bool unblock);
};

class Client {
public:
    void GetPpapiChannelInfo(base::ProcessHandle* process_handle, int* renderer_child_id);
    bool OffTheRecord();
    void OnPpapiChannelOpened(const IPC::ChannelHandle& handle, base::ProcessId process_id, int renderer_child_id);
};

class PpapiPluginProcessHost {
private:
    std::queue<Client*> sent_requests_;
public:
    void RequestPluginChannel(Client* client);
    bool Send(PpapiMsg_CreateChannel* msg);
};