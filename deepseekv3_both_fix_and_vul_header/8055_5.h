#include <stdint.h>

enum EditableType {
    ContentIsEditable,
    DoNotUpdateStyle
};

struct Position;
struct Node;
struct Element;
struct LayoutObject;
struct RootInlineBox;
struct InlineBox;
struct LineLayoutItem;
struct VisiblePosition;
struct RenderedPosition;

struct LayoutPoint {
    int32_t x;
    int32_t y;
};

struct LayoutUnit {
    int32_t value;
};

struct Document {
    void updateStyleAndLayoutIgnorePendingStylesheets();
    Element* documentElement();
};

struct Node {
    Document& document();
    LayoutObject* layoutObject();
    bool hasEditableStyle(EditableType);
    Element* rootEditableElement(EditableType);
    Position anchorNode();
};

struct Element : Node {
};

struct LayoutObject {
};

struct RootInlineBox {
    RootInlineBox* prevRootBox();
    int logicalHeight();
    InlineBox* firstLeafChild();
    LineLayoutItem* closestLeafChildForPoint(LayoutPoint point, bool editable);
};

struct InlineBox {
    RootInlineBox& root();
};

struct LineLayoutItem {
    Node* node();
    Position positionForPoint(LayoutPoint point);
    LineLayoutItem& getLineLayoutItem();
};

struct Position {
    Node* anchorNode();
    bool isNotNull();
};

struct VisiblePosition {
    Position deepEquivalent() const;
    static VisiblePosition inParentBeforeNode(Node& node);
    static VisiblePosition firstPositionInNode(Node* node);
    VisiblePosition();
};

struct RenderedPosition {
    RenderedPosition(const VisiblePosition& position);
    RootInlineBox* rootBox();
};

struct InlineBoxPosition {
    InlineBox* inlineBox;
};

InlineBoxPosition computeInlineBoxPosition(const VisiblePosition& position);
Position previousRootInlineBoxCandidatePosition(Node* node, const VisiblePosition& position, EditableType type);
bool isEditablePosition(const Position& position, EditableType type1, EditableType type2);
bool isEditablePosition(const Position& position);
bool editingIgnoresContent(Node* node);
LayoutPoint absoluteLineDirectionPointToLocalPointInBlock(RootInlineBox* box, LayoutUnit unit);
VisiblePosition createVisiblePosition(const Position& position);