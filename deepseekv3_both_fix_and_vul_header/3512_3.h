#include <stdbool.h>
#include <assert.h>

#define ASSERT assert

class RenderObject {
public:
    RenderObject* parent() const;
    bool isInline() const;
    bool isFloatingOrOutOfFlowPositioned() const;
    bool isAnonymous() const;
    bool isAnonymousBlock() const;
    bool isTable() const;
    bool isTablePart() const;
    bool isRenderFullScreen() const;
    bool isRenderFullScreenPlaceholder() const;
    bool isRenderBlock() const;
    RenderObject* firstChild() const;
    RenderObject* previousSibling() const;
    void addChild(RenderObject* newChild, RenderObject* beforeChild = nullptr);
};

class RenderBoxModelObject : public RenderObject {
};

class RenderBox : public RenderBoxModelObject {
public:
    static void addChild(RenderObject* newChild, RenderObject* beforeChild = nullptr);
};

class RenderBlockFlow;

class RenderBlock : public RenderBox {
public:
    void addChildIgnoringAnonymousColumnBlocks(RenderObject* newChild, RenderObject* beforeChild);
    bool childrenInline() const;
    RenderObject* lastChild() const;
    void makeChildrenNonInline(RenderObject* beforeChild);
    void makeChildrenAnonymousColumnBlocks(RenderObject* beforeChild, RenderBlockFlow* newBox, RenderObject* newChild);
    RenderBlockFlow* columnsBlockForSpanningElement(RenderObject* newChild);
    RenderBlockFlow* createAnonymousColumnSpanBlock();
    RenderBlock* createAnonymousBlock();
    RenderObject* splitAnonymousBoxesAroundChild(RenderObject* child);
    void splitFlow(RenderObject* beforeChild, RenderBlockFlow* newBox, RenderObject* newChild, RenderBoxModelObject* oldContinuation);
    RenderBoxModelObject* continuation() const;
    void setContinuation(RenderBoxModelObject*);
    void removeLeftoverAnonymousBlock(RenderBlock* child);
    bool isRenderFlowThread() const;
};

class RenderBlockFlow : public RenderBlock {
};

class RenderTable : public RenderBlock {
public:
    void addChild(RenderObject* newChild, RenderObject* beforeChild = nullptr);
};

extern bool gColumnFlowSplitEnabled;

template<typename T>
struct TemporaryChange {
    T& m_value;
    T m_oldValue;
    TemporaryChange(T& value, T newValue) : m_value(value), m_oldValue(value) { m_value = newValue; }
    ~TemporaryChange() { m_value = m_oldValue; }
};

static inline RenderTable* toRenderTable(RenderObject* object) {
    return static_cast<RenderTable*>(object);
}

static inline RenderBlock* toRenderBlock(RenderObject* object) {
    return static_cast<RenderBlock*>(object);
}