#include <string>
#include <memory>
#include <cassert>

#define ASSERT assert

using String = std::string;

template<typename T>
class RefPtrWillBeRawPtr {
public:
    RefPtrWillBeRawPtr(T* ptr = nullptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
    T* release() { T* temp = ptr_; ptr_ = nullptr; return temp; }
    T* operator->() const { return ptr_; }
    operator RefPtrWillBeRawPtr<void>() { return RefPtrWillBeRawPtr<void>(ptr_); }
private:
    T* ptr_;
};

class KURL {};
class CSSStyleSheetResource {
public:
    String sheetText(bool = false) const { return ""; }
};
class CSSParserContext {
public:
    CSSParserContext(void*, int, const KURL&, const String&) {}
};
class StyleSheetContents {
public:
    static RefPtrWillBeRawPtr<StyleSheetContents> create(const String&, const CSSParserContext&) { return nullptr; }
};
class CSSStyleSheet {
public:
    static RefPtrWillBeRawPtr<CSSStyleSheet> create(RefPtrWillBeRawPtr<StyleSheetContents>, class ProcessingInstruction*) { return nullptr; }
    void setDisabled(bool) {}
    void setTitle(const String&) {}
    void setMediaQueries(RefPtrWillBeRawPtr<void>) {}
};
class MediaQuerySet {
public:
    static RefPtrWillBeRawPtr<MediaQuerySet> create(const String&) { return nullptr; }
};

class ProcessingInstruction {
public:
    bool inDocument() { return false; }
    bool m_isCSS = false;
    bool m_alternate = false;
    String m_title;
    String m_media;
    CSSStyleSheet* m_sheet = nullptr;
    void parseStyleSheet(const String&) {}
    void* document() { return nullptr; }
    void setCSSStyleSheet(const String&, const KURL&, const String&, const CSSStyleSheetResource*);
};