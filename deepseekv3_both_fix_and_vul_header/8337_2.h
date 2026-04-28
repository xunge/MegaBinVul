#include <string>

namespace blink {
    class WebLocalFrame;
}

class Extension;
class GURL {
public:
    GURL();
    GURL(const GURL&);
    GURL& operator=(const GURL&);
    ~GURL();
};

class ScriptInjection {
public:
    static std::string GetHostIdForIsolatedWorld(int world_id);
};

class ScriptContext {
public:
    static GURL GetAccessCheckedFrameURL(const blink::WebLocalFrame* frame);
    static GURL GetDataSourceURLForFrame(const blink::WebLocalFrame* frame);
    static GURL GetEffectiveDocumentURL(const blink::WebLocalFrame* frame, 
                                      const GURL& frame_url,
                                      bool use_effective_url);
};

class RendererExtensionRegistry {
public:
    static RendererExtensionRegistry* Get();
    std::string GetExtensionOrAppIDByURL(const GURL& url);
    const Extension* GetByID(const std::string& id);
};

class ScriptContextSet {
public:
    static const Extension* GetExtensionFromFrameAndWorld(
        const blink::WebLocalFrame* frame,
        int world_id,
        bool use_effective_url);
};