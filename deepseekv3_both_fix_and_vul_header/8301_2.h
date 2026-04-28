#include <stddef.h>

class Frame {
public:
    bool parent();
    void* dataSource();
};

class NavigationStateImpl;

class DocumentState {
public:
    static DocumentState* FromDataSource(void* dataSource);
    NavigationStateImpl* navigation_state();
};

class NavigationStateImpl {
public:
    bool request_committed();
};

class FrameHostMsg_DidAccessInitialDocument {
public:
    FrameHostMsg_DidAccessInitialDocument(int routing_id);
};

class RenderFrameImpl {
public:
    Frame* frame_;
    int routing_id_;
    void didAccessInitialDocument();
};

void Send(FrameHostMsg_DidAccessInitialDocument* msg);