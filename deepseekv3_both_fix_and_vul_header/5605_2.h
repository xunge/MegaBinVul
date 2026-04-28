#include <map>
#include <vector>

namespace blink {
class WebFrame {
public:
    WebFrame* parent();
    void removeChild(WebFrame* frame);
    void close();
};
}

class FrameHostMsg_Detach {
public:
    FrameHostMsg_Detach(int routing_id);
};

class RenderFrameObserver;
class RenderViewObserver;

struct FrameMap {
    typedef std::map<blink::WebFrame*, class RenderFrameImpl*>::iterator iterator;
    static std::map<blink::WebFrame*, class RenderFrameImpl*>& Get();
};

class RenderFrameImpl {
public:
    void frameDetached(blink::WebFrame* frame);
    void Send(FrameHostMsg_Detach* msg);
    
    int routing_id_;
    bool is_detaching_;
    blink::WebFrame* frame_;
    std::vector<RenderFrameObserver*> observers_;
    class RenderViewImpl* render_view_;
};

extern FrameMap g_frame_map;

#define CHECK(expr) 
#define DCHECK(expr) 
#define CHECK_EQ(a, b) 
#define FOR_EACH_OBSERVER(ObserverType, observer_list, func) 