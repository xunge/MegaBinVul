#include <stdbool.h>

namespace IPC {
    struct Message {};
}

struct OwnerDelegate {
    bool OnMessageReceived(const IPC::Message& msg);
};

struct InputRouter {
    bool OnMessageReceived(const IPC::Message& msg);
};

struct View {
    bool OnMessageReceived(const IPC::Message& msg);
};

struct RenderWidgetHostImpl {
    bool renderer_initialized();
    bool OnMessageReceived(const IPC::Message& msg);
    
    OwnerDelegate* owner_delegate_;
    InputRouter* input_router_;
    View* view_;
};

struct FrameHostMsg_RenderProcessGone {};
struct FrameHostMsg_HittestData {};
struct InputHostMsg_QueueSyntheticGesture {};
struct InputHostMsg_ImeCancelComposition {};
struct ViewHostMsg_Close {};
struct ViewHostMsg_UpdateScreenRects_ACK {};
struct ViewHostMsg_RequestMove {};
struct ViewHostMsg_SetTooltipText {};
struct ViewHostMsg_SwapCompositorFrame {};
struct ViewHostMsg_UpdateRect {};
struct ViewHostMsg_SetCursor {};
struct ViewHostMsg_TextInputStateChanged {};
struct ViewHostMsg_LockMouse {};
struct ViewHostMsg_UnlockMouse {};
struct ViewHostMsg_ShowDisambiguationPopup {};
struct ViewHostMsg_SelectionChanged {};
struct ViewHostMsg_SelectionBoundsChanged {};
struct ViewHostMsg_WindowlessPluginDummyWindowCreated {};
struct ViewHostMsg_WindowlessPluginDummyWindowDestroyed {};
struct InputHostMsg_ImeCompositionRangeChanged {};
struct ViewHostMsg_DidFirstPaintAfterLoad {};
struct ViewHostMsg_ForwardCompositorProto {};

#define IPC_BEGIN_MESSAGE_MAP(a, b)
#define IPC_MESSAGE_HANDLER(a, b)
#define IPC_MESSAGE_HANDLER_GENERIC(a, b)
#define IPC_MESSAGE_UNHANDLED(a)
#define IPC_END_MESSAGE_MAP()

#define OS_WIN 1