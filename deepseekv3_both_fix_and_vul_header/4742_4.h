#include <memory>

class NativeHandler {
public:
    virtual ~NativeHandler() {}
};

class ScriptContext {};

class ModuleSystem {
public:
    void RegisterNativeHandler(const char* name, std::unique_ptr<NativeHandler> handler);
};

class Dispatcher {
public:
    void RegisterNativeHandlers(ModuleSystem* module_system,
                              ScriptContext* context,
                              Dispatcher* dispatcher,
                              class RequestSender* request_sender,
                              class V8SchemaRegistry* v8_schema_registry);
};

class RequestSender {};
class V8SchemaRegistry {
public:
    std::unique_ptr<NativeHandler> AsNativeHandler();
};

class ChromeNativeHandler : public NativeHandler {
public:
    explicit ChromeNativeHandler(ScriptContext* context) {}
};
class LoggingNativeHandler : public NativeHandler {
public:
    explicit LoggingNativeHandler(ScriptContext* context) {}
};
class TestFeaturesNativeHandler : public NativeHandler {
public:
    explicit TestFeaturesNativeHandler(ScriptContext* context) {}
};
class TestNativeHandler : public NativeHandler {
public:
    explicit TestNativeHandler(ScriptContext* context) {}
};
class UserGesturesNativeHandler : public NativeHandler {
public:
    explicit UserGesturesNativeHandler(ScriptContext* context) {}
};
class UtilsNativeHandler : public NativeHandler {
public:
    explicit UtilsNativeHandler(ScriptContext* context) {}
};
class V8ContextNativeHandler : public NativeHandler {
public:
    explicit V8ContextNativeHandler(ScriptContext* context) {}
};
class EventBindings : public NativeHandler {
public:
    explicit EventBindings(ScriptContext* context) {}
};
class MessagingBindings : public NativeHandler {
public:
    static std::unique_ptr<NativeHandler> Get(Dispatcher* dispatcher, ScriptContext* context);
};
class ApiDefinitionsNatives : public NativeHandler {
public:
    ApiDefinitionsNatives(Dispatcher* dispatcher, ScriptContext* context) {}
};
class SendRequestNatives : public NativeHandler {
public:
    SendRequestNatives(RequestSender* request_sender, ScriptContext* context) {}
};
class SetIconNatives : public NativeHandler {
public:
    explicit SetIconNatives(ScriptContext* context) {}
};
class APIActivityLogger : public NativeHandler {
public:
    explicit APIActivityLogger(ScriptContext* context) {}
};
class RenderFrameObserverNatives : public NativeHandler {
public:
    explicit RenderFrameObserverNatives(ScriptContext* context) {}
};
class FileSystemNatives : public NativeHandler {
public:
    explicit FileSystemNatives(ScriptContext* context) {}
};
class AppWindowCustomBindings : public NativeHandler {
public:
    explicit AppWindowCustomBindings(ScriptContext* context) {}
};
class BlobNativeHandler : public NativeHandler {
public:
    explicit BlobNativeHandler(ScriptContext* context) {}
};
class ContextMenusCustomBindings : public NativeHandler {
public:
    explicit ContextMenusCustomBindings(ScriptContext* context) {}
};
class CssNativeHandler : public NativeHandler {
public:
    explicit CssNativeHandler(ScriptContext* context) {}
};
class DocumentCustomBindings : public NativeHandler {
public:
    explicit DocumentCustomBindings(ScriptContext* context) {}
};
class GuestViewInternalCustomBindings : public NativeHandler {
public:
    explicit GuestViewInternalCustomBindings(ScriptContext* context) {}
};
class IdGeneratorCustomBindings : public NativeHandler {
public:
    explicit IdGeneratorCustomBindings(ScriptContext* context) {}
};
class RuntimeCustomBindings : public NativeHandler {
public:
    explicit RuntimeCustomBindings(ScriptContext* context) {}
};
class DisplaySourceCustomBindings : public NativeHandler {
public:
    explicit DisplaySourceCustomBindings(ScriptContext* context) {}
};
class LazyBackgroundPageNativeHandler : public NativeHandler {
public:
    explicit LazyBackgroundPageNativeHandler(ScriptContext* context) {}
};
class PrintNativeHandler : public NativeHandler {
public:
    explicit PrintNativeHandler(ScriptContext* context) {}
};
class I18NCustomBindings : public NativeHandler {
public:
    explicit I18NCustomBindings(ScriptContext* context) {}
};

template <typename T>
class scoped_ptr {
public:
    explicit scoped_ptr(T* ptr) : ptr_(ptr) {}
    explicit scoped_ptr(std::unique_ptr<T>&& other) : ptr_(other.release()) {}
    ~scoped_ptr() { delete ptr_; }
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    operator std::unique_ptr<T>() { return std::unique_ptr<T>(ptr_); ptr_ = nullptr; }
private:
    T* ptr_;
};