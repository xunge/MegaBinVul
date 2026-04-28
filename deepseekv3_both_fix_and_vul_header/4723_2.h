#include <iostream>

namespace blink {
    class WebSecurityOrigin {
    public:
        bool canAccessPasswordManager() const;
    };
}

class PasswordGenerationAgent {
public:
    class RenderFrame {
    public:
        class WebFrame {
        public:
            class Document {
            public:
                blink::WebSecurityOrigin getSecurityOrigin() const;
            };
            Document document() const;
        };
        WebFrame* GetWebFrame() const;
    };
    RenderFrame* render_frame() const;
    bool ShouldAnalyzeDocument() const;
};

namespace logging {
    class Vlog {
    public:
        template<typename T>
        Vlog& operator<<(const T&);
    };
    Vlog VLOG(int level);
}

using logging::VLOG;