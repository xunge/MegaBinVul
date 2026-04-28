#include <memory>

namespace content {
class WebContents;
}

namespace pdf {
class PDFWebContentsHelper {
 public:
  static PDFWebContentsHelper* FromWebContents(content::WebContents* web_contents);
  void* open_in_reader_prompt();
};
}

class Bubble {
 public:
  class Widget* GetWidget();
};

class Widget {
 public:
  void Hide();
};

class OpenPDFInReaderView {
 private:
  void* model_;
  std::unique_ptr<Bubble> bubble_;

 public:
  void Update(content::WebContents* web_contents);
  void SetVisible(bool visible);
};