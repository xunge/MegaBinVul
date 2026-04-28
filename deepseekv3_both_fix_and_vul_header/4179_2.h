#include <stdbool.h>

class LayoutObject;

enum MarkingBehavior {
    MarkContainerChain
};

enum LayoutInvalidationReasonForTracing {
    TRACE_DISABLED_BY_DEFAULT
};

class SubtreeLayoutScope {
public:
    LayoutObject* root();
};

class InspectorLayoutInvalidationTrackingEvent {
public:
    static void* data(LayoutObject*, LayoutInvalidationReasonForTracing);
};

class LayoutObject {
public:
    void setNeedsLayout(LayoutInvalidationReasonForTracing, MarkingBehavior, SubtreeLayoutScope*);
    bool isSetNeedsLayoutForbidden();
    void setSelfNeedsLayout(bool);
    void markContainerChainForLayout(bool, SubtreeLayoutScope*);
    void markContainerChainForLayout(SubtreeLayoutScope*);
    
    struct {
        bool selfNeedsLayout() { return false; }
    } m_bitfields;
};

#define ASSERT(expr) ((void)0)
#define TRACE_EVENT_INSTANT1(category, name, scope, arg1_name, arg1_val) ((void)0)
#define TRACE_EVENT_SCOPE_THREAD 0