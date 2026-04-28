#include <map>
#include <utility>
#include <string>
#include <tuple>

class GURL {
public:
    GURL();
    GURL(const std::string& url);
    std::string spec() const;
};

namespace IPC {
class Message {
public:
    virtual ~Message();
};
}

namespace blink {
class WebView {
public:
    class WebLocalFrame* mainFrame();
};
class WebLocalFrame {
public:
    class WebView* view() const;
    class WebLocalFrame* top() const;
    class WebDocument document() const;
};
class WebDocument {
public:
    GURL url() const;
};
}  // namespace blink

namespace content {
class RenderView {
public:
    static RenderView* FromWebView(blink::WebView* web_view);
    int GetRoutingID() const;
};
class RenderThread {
public:
    static RenderThread* Get();
    void Send(IPC::Message* message);
};
class RenderFrame {
public:
    static RenderFrame* FromWebFrame(blink::WebLocalFrame* web_frame);
};
}  // namespace content

struct PermissionsData {
    enum AccessType {
        ACCESS_ALLOWED,
        ACCESS_DENIED
    };
};

class InjectionHost {
public:
    PermissionsData::AccessType CanExecuteOnFrame(
        const GURL& effective_document_url,
        content::RenderFrame* render_frame,
        int tab_id,
        bool is_declarative) const;
};

class UserScript {
public:
    enum class ConsumerInstanceType {
        WEBVIEW
    };
    ConsumerInstanceType consumer_instance_type() const;
    int id() const;
    bool match_about_blank() const;
};

class ScriptContext {
public:
    static GURL GetEffectiveDocumentURL(
        blink::WebLocalFrame* web_frame,
        const GURL& document_url,
        bool match_about_blank);
};

struct RoutingInfoKey {
    int routing_id;
    int script_id;
    RoutingInfoKey(int routing_id, int script_id)
        : routing_id(routing_id), script_id(script_id) {}
    bool operator<(const RoutingInfoKey& other) const {
        return std::tie(routing_id, script_id) <
               std::tie(other.routing_id, other.script_id);
    }
};

using RoutingInfoMap = std::map<RoutingInfoKey, bool>;

template <typename T>
class SingletonHolder {
public:
    static T& Get() {
        static T instance;
        return instance;
    }
};

SingletonHolder<RoutingInfoMap> g_routing_info_map;

class ExtensionsGuestViewHostMsg_CanExecuteContentScriptSync : public IPC::Message {
public:
    ExtensionsGuestViewHostMsg_CanExecuteContentScriptSync(
        int routing_id,
        int script_id,
        bool* allowed);
};

class UserScriptInjector {
public:
    PermissionsData::AccessType CanExecuteOnFrame(
        const InjectionHost* injection_host,
        blink::WebLocalFrame* web_frame,
        int tab_id) const;
private:
    UserScript* script_;
    bool is_declarative_;
};