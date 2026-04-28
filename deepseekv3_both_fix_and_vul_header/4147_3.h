#include <stdbool.h>
#include <cassert>

class LayoutBoxModelObject;

class LayoutObject {
public:
    LayoutObject* previousSibling();
    LayoutObject* nextSibling();
    bool isAnonymousBlock();
    bool isAnonymous();
    bool isFloating();
    bool isFloatingOrOutOfFlowPositioned();
    bool isListMarker();
    bool hasLayer();
    bool childrenInline();
    class Style {
    public:
        int styleType();
    };
    Style* style();
    LayoutObject* containingBlock();
    LayoutObject* virtualContinuation();
    bool isLayoutInline();
    bool isLayoutBlock();
    void setNeedsLayoutAndPrefWidthsRecalcAndFullPaintInvalidation(int reason);
    LayoutObject* firstChild();
    LayoutObject* previousInPreOrder(LayoutObject*);
};

class LayoutBox : public LayoutObject {
public:
    void removeChild(LayoutObject* oldChild);
};

class LayoutBlock : public LayoutBox {
public:
    void removeChild(LayoutObject* oldChild);
    bool documentBeingDestroyed();
    bool canMergeContiguousAnonymousBlocks(LayoutObject*, LayoutObject*, LayoutObject*);
    bool canCollapseAnonymousBlockChild();
    void collapseAnonymousBlockChild(LayoutBlock*, LayoutBlock*);
    bool beingDestroyed();
    bool isAnonymousBlockContinuation();
    LayoutBoxModelObject* continuation();
    void setContinuation(LayoutBoxModelObject*);
    void destroy();
    bool isLayoutBlockFlow();
    void makeChildrenInlineIfPossible();
    bool shouldMakeChildrenInline(LayoutBlock*);
    void setChildrenInline(bool);
    void deleteLineBoxTree();
    class Children {
    public:
        void removeChildNode(LayoutBlock*, LayoutBlock*, bool);
        void insertChildNode(LayoutBlock*, LayoutBlock*, LayoutObject*, bool);
    };
    Children* children();
};

class LayoutBlockFlow : public LayoutBlock {
public:
    void moveAllChildrenIncludingFloatsTo(LayoutBlock*, bool);
};

class LayoutBoxModelObject : public LayoutObject {
};

class LayoutInline : public LayoutBoxModelObject {
public:
    void setContinuation(LayoutBoxModelObject*);
};

enum LayoutInvalidationReason {
    AnonymousBlockChange
};

enum PseudoId {
    NOPSEUDO
};

inline LayoutBlockFlow* toLayoutBlockFlow(LayoutObject* object) {
    return static_cast<LayoutBlockFlow*>(object);
}

inline LayoutBlock* toLayoutBlock(LayoutObject* object) {
    return static_cast<LayoutBlock*>(object);
}

inline LayoutInline* toLayoutInline(LayoutObject* object) {
    return static_cast<LayoutInline*>(object);
}

#define ASSERT(expr) assert(expr)
#define ASSERT_NOT_REACHED() assert(false)