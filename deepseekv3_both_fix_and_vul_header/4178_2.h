#include <assert.h>
#include <stdbool.h>

enum MarkingBehavior {
    MarkContainerChain
};

class LayoutObject;

class SubtreeLayoutScope {
public:
    LayoutObject* root();
};

class LayoutObject {
public:
    bool isSetNeedsLayoutForbidden();
    bool normalChildNeedsLayout();
    void setNormalChildNeedsLayout(bool);
    void markContainerChainForLayout(SubtreeLayoutScope*);
    void markContainerChainForLayout(bool, SubtreeLayoutScope*);
    void setChildNeedsLayout(MarkingBehavior, SubtreeLayoutScope*);
};

#define ASSERT assert