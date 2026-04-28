#include <memory>
#include <string>
#include <cassert>

class KURL {
public:
    KURL();
    KURL(const std::string&);
    std::string string() const;
    const KURL& url() const;
};

class Document {
public:
    const KURL& url() const;
};

class Referrer {
public:
    std::string url;
};

class ScheduledPageBlock {
public:
    ScheduledPageBlock(Document*, const KURL&, const Referrer&);
    ~ScheduledPageBlock();
};

class ScheduledLocationChange {
public:
    ScheduledLocationChange(Document*, const KURL&, const Referrer&, bool);
    ~ScheduledLocationChange();
};

class Frame {
public:
    Document* document();
    bool page();
};

class SecurityOrigin {
public:
    static KURL urlWithUniqueSecurityOrigin();
};

class NavigationScheduler {
public:
    Frame* m_frame;
    
    void schedule(std::unique_ptr<ScheduledPageBlock>);
    void schedule(std::unique_ptr<ScheduledLocationChange>);
    static KURL urlWithUniqueSecurityOrigin();
    void schedulePageBlock(Document* originDocument, const Referrer& referrer);
};

template<typename T>
std::unique_ptr<T> adoptPtr(T* ptr) {
    return std::unique_ptr<T>(ptr);
}

#define ASSERT(expr) assert(expr)