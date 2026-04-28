#include <stdbool.h>

class IPC {
public:
    class Message {
    public:
        bool is_sync() const;
        void set_reply_error();
    };
    class SyncMessage {
    public:
        static Message* GenerateReply(const Message* msg);
    };
};

class SwappedOutMessages {
public:
    static bool CanHandleWhileSwappedOut(const IPC::Message& msg);
};

class RenderFrameProxyHost {
public:
    class CrossProcessFrameConnector {
    public:
        bool OnMessageReceived(const IPC::Message& msg);
    };
    CrossProcessFrameConnector* cross_process_frame_connector();
};

class FrameTreeNode {
public:
    class RenderManager {
    public:
        RenderFrameProxyHost* GetProxyToParent();
    };
    RenderManager* render_manager();
};

class Delegate {
public:
    bool OnMessageReceived(void* host, const IPC::Message& msg);
};

class RenderFrameHostImpl {
public:
    bool render_frame_created_;
    bool is_swapped_out();
    void Send(IPC::Message* msg);
    bool OnMessageReceived(const IPC::Message& msg);
    Delegate* delegate_;
    FrameTreeNode* frame_tree_node_;
};

#define IPC_BEGIN_MESSAGE_MAP(a, b)
#define IPC_MESSAGE_HANDLER(a, b)
#define IPC_MESSAGE_HANDLER_GENERIC(a, b)
#define IPC_MESSAGE_HANDLER_DELAY_REPLY(a, b)
#define IPC_MESSAGE_UNHANDLED(a)
#define IPC_END_MESSAGE_MAP()

#define OS_MACOSX 1
#define OS_ANDROID 1