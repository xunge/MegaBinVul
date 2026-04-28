#include <stdbool.h>

struct Node;
struct TagQName {};
struct Element {
    bool hasTagName(int tag);
    Element* previousElementSibling();
    Element* nextElementSibling();
    const TagQName& tagQName() const;
};
struct Position {
    Node* deprecatedNode() const;
};
struct Document {
    Element* createElement(const TagQName& name, bool flag);
};
struct IndentOutdentCommand {
    bool tryIndentingAsListItem(const Position& start, const Position& end);
};
Document& document();

template<typename T>
struct RefPtr {
    T* ptr;
    RefPtr(T* p = nullptr) : ptr(p) {}
    T* get() const { return ptr; }
    explicit operator bool() const { return ptr != nullptr; }
    T* operator->() const { return ptr; }
    operator T*() const { return ptr; }
};

#define liTag 0

Element* enclosingList(Node* node);
Element* enclosingBlock(Node* node);
void insertNodeBefore(Element* newNode, Element* refNode);
void moveParagraphWithClones(const Position& start, const Position& end, Element* newList, Element* selectedListItem);
bool canMergeLists(Element* list1, Element* list2);
void mergeIdenticalElements(Element* list1, Element* list2);