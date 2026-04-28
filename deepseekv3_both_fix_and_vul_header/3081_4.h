#include <stddef.h>
#include <string>

#define TYPE_MISMATCH_ERR 1
#define INUSE_ATTRIBUTE_ERR 2
#define notFound ((size_t)-1)
#define NotInSynchronizationOfLazyAttribute false

class String : public std::string {};

class Attr;
class Element;
class UniqueElementData;
class Document;
class QualifiedName;
class TreeScope;
class NodeList;

template<typename T> class RefPtr;
template<typename T> class PassRefPtr;

class ExceptionCode {
public:
    ExceptionCode& operator=(int);
};

template<typename T>
class RefPtr {
public:
    T* get() const { return nullptr; }
    T* release() { return nullptr; }
    operator bool() const { return get() != nullptr; }
};

template<typename T>
class PassRefPtr {
public:
    PassRefPtr(T*) {}
    PassRefPtr() {}
    operator T*() { return nullptr; }
};

class Attr {
public:
    QualifiedName qualifiedName();
    Element* ownerElement();
    void attachToElement(Element*);
    String value();
    static RefPtr<Attr> create(Document&, const QualifiedName&, const String&);
};

class Element {
public:
    PassRefPtr<Attr> setAttributeNode(Attr*, ExceptionCode&);
    RefPtr<Attr> attrIfExists(const QualifiedName&);
    void synchronizeAllAttributes();
    UniqueElementData* ensureUniqueElementData();
    void setAttributeInternal(size_t, const QualifiedName&, const String&, bool);
    Document& document();
    void detachAttrNodeFromElementWithValue(Attr*, const String&);
    TreeScope* treeScope();
    void adoptIfNeeded(Attr*);
    static NodeList* ensureAttrNodeListForElement(Element*);
};

class UniqueElementData {
public:
    size_t getAttributeItemIndex(const QualifiedName&);
    class AttributeItem* attributeItem(size_t);
};

class AttributeItem {
public:
    String value();
};

class TreeScope {
public:
    void adoptIfNeeded(Attr*);
};

class NodeList {
public:
    void append(Attr*);
};

class QualifiedName {};
class Document {};