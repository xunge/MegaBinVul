#include <string>
#include <memory>
#include <vector>
#include <iostream>

#define CHECK_LE(a, b) ((a) <= (b))
#define NOTREACHED() (void(0))
#define LOG(severity) std::cerr

namespace base {
class DictionaryValue;
template <typename T> class AutoReset {
 public:
  AutoReset(T* ptr, T value) : ptr_(ptr), original_value_(*ptr) { *ptr = value; }
  ~AutoReset() { *ptr_ = original_value_; }
 private:
  T* ptr_;
  T original_value_;
};
}  // namespace base

namespace blink {
class WebFrame;
class WebLocalFrame;
class WebDocument;
class WebElement;

class WebView {
 public:
  WebFrame* mainFrame();
};

class WebFrame {
 public:
  WebDocument document();
};

class WebLocalFrame {
 public:
  static WebLocalFrame* fromFrameOwnerElement(const WebElement&);
};

class WebDocument {
 public:
  WebElement getElementById(const std::string& id);
  WebLocalFrame* frame();
};

class WebElement {
 public:
  bool isNull() const;
  bool hasHTMLTagName(const std::string& tag) const;
  WebDocument document() const;
};
}  // namespace blink

namespace gfx {
class Size {
 public:
  Size() = default;
  Size(int width, int height) : width_(width), height_(height) {}
  int width() const { return width_; }
  int height() const { return height_; }
 private:
  int width_ = 0;
  int height_ = 0;
};

class Rect {
 public:
  Rect() = default;
  explicit Rect(const Size& size) : size_(size) {}
  const Size& size() const { return size_; }
 private:
  Size size_;
};
}  // namespace gfx

enum PrintResult {
  FAIL_PRINT,
  OK_PRINT
};

struct PrintMsg_Print_Params {
  gfx::Size page_size;
  gfx::Rect printable_area;
};

class RenderView {
 public:
  blink::WebView* GetWebView();
};

class PrintWebViewHelper {
 public:
  void OnPrintForPrintPreview(const base::DictionaryValue& job_settings);
 private:
  bool prep_frame_view_;
  bool print_for_preview_;
  int ipc_nesting_level_;
  RenderView* render_view() { return nullptr; }
  bool UpdatePrintSettings(blink::WebLocalFrame* frame, 
                         const blink::WebElement& element,
                         const base::DictionaryValue& settings) { return false; }
  void DidFinishPrinting(PrintResult result) {}
  bool RenderPagesForPrint(blink::WebLocalFrame* frame,
                         const blink::WebElement& element) { return false; }
  struct PrintPagesParams {
    PrintMsg_Print_Params params;
  };
  std::unique_ptr<PrintPagesParams> print_pages_params_;
  class Delegate {
   public:
    blink::WebElement GetPdfElement(blink::WebLocalFrame* frame) { return blink::WebElement(); }
  };
  Delegate* delegate_;
};