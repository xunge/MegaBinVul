#include <stdint.h>
#include <algorithm>

class blink {
public:
    class WebLocalFrame;
};

class PrintWebViewHelper {
public:
    void OnPrintPages();
private:
    int ipc_nesting_level_;
    class Delegate {
    public:
        void* GetPdfElement(blink::WebLocalFrame* frame);
    };
    Delegate* delegate_;

    bool GetPrintFrame(blink::WebLocalFrame** frame);
    void Print(blink::WebLocalFrame* frame, void* plugin, bool flag);
};

#define CHECK_LE(a, b) std::max(a, b)