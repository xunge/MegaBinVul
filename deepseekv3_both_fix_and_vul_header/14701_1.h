#include <cstddef>

namespace blink {
class WebLocalFrame;
}

class PrintWebViewHelper {
public:
    struct PrintPreviewContext {
        blink::WebLocalFrame* source_frame();
        void* source_node();
    };

    void Print(blink::WebLocalFrame* frame, void* node, bool preview);
    void OnPrintForSystemDialog();
    int ipc_nesting_level_;
    PrintPreviewContext print_preview_context_;
};

#define CHECK_LE(a, b)
#define NOTREACHED()