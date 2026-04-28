#include <vector>

struct Ref {
    int num;
    int gen;
};

class Object {
public:
    bool isDict() const;
    const Object& dictLookupNF(const char* key) const;
};

class XRef {
public:
    Object fetch(const Ref& ref);
};

class PDFDoc;

class OutlineItem {
public:
    void open();
    std::vector<OutlineItem*>* kids;
    Ref ref;
    XRef* xref;
    PDFDoc* doc;
};

extern std::vector<OutlineItem*>* readItemList(OutlineItem* item, const Object* firstRef, XRef* xref, PDFDoc* doc);