#include <memory>
#include <cassert>

namespace v8 {
    class Value {};
    template<typename T> class Local {
    public:
        T* operator->() const;
        T* Get() const;
    };
    class Object : public Value {};
    class Context : public Object {
    public:
        Local<Object> Global();
    };
    class Isolate {
    public:
        Local<Context> GetCurrentContext();
    };
}

enum EntryType {
    EntryTypeDirectory,
    EntryTypeFile
};

class WebString {
public:
    WebString(const char*);
    ~WebString();
};

class WebDOMFileSystemPrivate;

class DirectoryEntry {
public:
    static DirectoryEntry* create(WebDOMFileSystemPrivate*, const WebString&);
};

class FileEntry {
public:
    static FileEntry* create(WebDOMFileSystemPrivate*, const WebString&);
};

class WebDOMFileSystem {
private:
    std::unique_ptr<WebDOMFileSystemPrivate> m_private;
public:
    v8::Local<v8::Value> createV8Entry(const WebString&, EntryType, v8::Local<v8::Object>, v8::Isolate*);
};

template<typename T>
v8::Local<v8::Value> toV8(T*, v8::Local<v8::Object>, v8::Isolate*);

#define ASSERT(expr) assert(expr)