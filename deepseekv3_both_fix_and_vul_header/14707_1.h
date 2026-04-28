#include <stddef.h>

#define CHECK_LE(a, b) ((void)0)
#define DCHECK(condition) ((void)0)

namespace blink {
class WebLocalFrame;
class WebElement {
public:
    bool isNull() const { return false; }
};
}  // namespace blink

class PrintWebViewHelper {
public:
    struct PrintPreviewContext {
        void InitWithFrame(blink::WebLocalFrame* frame) {}
    };
    
    class Delegate {
    public:
        blink::WebElement GetPdfElement(blink::WebLocalFrame* frame) { return blink::WebElement(); }
    };

    void GetPrintFrame(blink::WebLocalFrame** frame) {}
    void PrintNode(const blink::WebElement& element) {}
    void RequestPrintPreview(int mode) {}
    void OnInitiatePrintPreview(bool selection_only);

    int ipc_nesting_level_;
    PrintPreviewContext print_preview_context_;
    Delegate* delegate_;
};

enum {
    PRINT_PREVIEW_USER_INITIATED_SELECTION,
    PRINT_PREVIEW_USER_INITIATED_ENTIRE_FRAME
};