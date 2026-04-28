#include <string>
#include <vector>

namespace v8 {

class Value {
public:
    bool IsString() const;
    bool IsBoolean() const;
    bool BooleanValue() const;
};

class Object;
class Isolate;

template <typename T>
class Local;

class Context {
public:
    Local<Object> Global();
};

template <typename T> 
class Local {
public:
    T* operator->() const;
    operator T*() const;
};

template <typename T>
class ReturnValue;

template <typename T>
class FunctionCallbackInfo {
public:
    int Length() const;
    Local<Value> operator[](int) const;
    ReturnValue<T> GetReturnValue() const;
    Isolate* GetIsolate() const;
};

template <typename T>
class ReturnValue {
public:
    void Set(Local<Value>);
};

class String {
public:
    class Utf8Value {
    public:
        explicit Utf8Value(Local<Value>);
        operator std::string*();
    };
};

}  // namespace v8

struct GURL {
    explicit GURL(const std::string&);
};

namespace base {
class FilePath {
public:
    static FilePath FromUTF8Unsafe(const std::string&);
    std::string value() const;
};
}  // namespace base

namespace blink {
enum WebFileSystemType {};
class WebString {
public:
    static WebString fromUTF8(const std::string&);
};
class WebLocalFrame {
public:
    static WebLocalFrame* frameForContext(v8::Local<v8::Context>);
};
class WebDOMFileSystem {
public:
    enum EntryType { EntryTypeDirectory, EntryTypeFile };
    static WebDOMFileSystem create(WebLocalFrame*, WebFileSystemType, WebString, GURL);
    v8::Local<v8::Value> createV8Entry(WebString, EntryType, v8::Local<v8::Object>, v8::Isolate*);
};
}  // namespace blink

namespace storage {
bool GetFileSystemPublicType(const std::string&, blink::WebFileSystemType*);
class VirtualPath {
public:
    static bool IsAbsolute(const std::string&);
};
}  // namespace storage

class FileSystemNatives {
public:
    FileSystemNatives* context();
    v8::Local<v8::Context> v8_context() const;
    void GetFileEntry(const v8::FunctionCallbackInfo<v8::Value>& args);
};

#define DCHECK(condition) (void)(condition)
#define CHECK(condition) DCHECK(condition)
#define CHECK_EQ(a, b) CHECK((a) == (b))