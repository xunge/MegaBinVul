#include <stddef.h>

class ComputedStyle;
class TextAutosizer;
class Document;

enum PositionType {
    StaticPosition
};

enum NewContainingBlockType {
    NewContainingBlock
};

struct StyleDifference {
    bool needsFullLayout() const { return false; }
};

class LayoutBox {
public:
    void styleDidChange(StyleDifference, const ComputedStyle*);
};

class LayoutBlock : public LayoutBox {
public:
    void styleDidChange(StyleDifference, const ComputedStyle*);
    bool isFloatingOrOutOfFlowPositioned() const { return false; }
    LayoutBlock* parent() const { return nullptr; }
    bool isLayoutBlockFlow() const { return false; }
    void makeChildrenInlineIfPossible() {}
    void removeAnonymousWrappersIfRequired() {}
    LayoutBlock* previousSibling() const { return nullptr; }
    bool isAnonymousBlock() const { return false; }
    void moveChildTo(LayoutBlock*, LayoutBlock*, void*, bool) {}
    LayoutBlock* nextSibling() const { return nullptr; }
    void* slowFirstChild() const { return nullptr; }
    const ComputedStyle& styleRef() const;
    LayoutBlock* containingBlock() const { return nullptr; }
    void removePositionedObjects(LayoutBlock*, NewContainingBlockType) {}
    Document& document() const;
    void propagateStyleToAnonymousChildren(bool) {}
    bool needsLayout() const { return false; }
    bool borderOrPaddingLogicalWidthChanged(const ComputedStyle&, const ComputedStyle&) const { return false; }
    bool m_widthAvailableToChildrenChanged;
};

class ComputedStyle {
public:
    bool isFloating() const { return false; }
    bool hasOutOfFlowPosition() const { return false; }
    PositionType position() const { return StaticPosition; }
};

class TextAutosizer {
public:
    void record(LayoutBlock*) {}
};

class Document {
public:
    TextAutosizer* textAutosizer() const { return nullptr; }
};

inline LayoutBlock* toLayoutBlock(void* obj) {
    return static_cast<LayoutBlock*>(obj);
}