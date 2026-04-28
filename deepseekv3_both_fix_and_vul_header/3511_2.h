#include <stdbool.h>
#include <assert.h>

#define ASSERT assert
#define ASSERT_WITH_SECURITY_IMPLICATION assert
#define ASSERT_NOT_REACHED() assert(false)

class RenderObject;
class RenderCounter;
class AXObjectCache;

class RenderObjectChildList {
public:
    RenderObject* firstChild();
    void setFirstChild(RenderObject*);
    RenderObject* lastChild();
    void setLastChild(RenderObject*);
    void insertChildNode(RenderObject* owner, RenderObject* newChild, RenderObject* beforeChild, bool notifyRenderer);
};

class RenderObject {
public:
    bool isRenderBlockFlow();
    bool isTableSection();
    bool isTableRow();
    bool isTableCell();
    bool isTable();
    bool isTableCaption();
    bool isRenderTableCol();
    RenderObject* parent();
    void setParent(RenderObject*);
    RenderObject* previousSibling();
    void setPreviousSibling(RenderObject*);
    RenderObject* nextSibling();
    void setNextSibling(RenderObject*);
    bool documentBeingDestroyed();
    void insertedIntoTree();
    void setNeedsLayoutAndPrefWidthsRecalc();
    bool normalChildNeedsLayout();
    void setChildNeedsLayout();
    class Document {
    public:
        AXObjectCache* axObjectCache();
    };
    Document& document();
};

class RenderCounter {
public:
    static void rendererSubtreeAttached(RenderObject*);
};

class AXObjectCache {
public:
    void childrenChanged(RenderObject*);
};