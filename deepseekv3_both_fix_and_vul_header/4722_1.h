#include <string>
#include <vector>

namespace base {
typedef std::u16string string16;
}

namespace password_generation {
enum PasswordGenerationEvent {
  PASSWORD_ACCEPTED
};
void LogPasswordGenerationEvent(PasswordGenerationEvent event);
}

class PasswordGenerationAgent {
public:
  bool password_is_generated_;
  struct FormData {
    struct PasswordElement {
      void setValue(const base::string16& password, bool flag);
      void setAutofilled(bool flag);
    };
    std::vector<PasswordElement> password_elements;
  };
  FormData* generation_form_data_;
  class PasswordAgent {
  public:
    void UpdateStateForTextChange(FormData::PasswordElement& element);
  };
  PasswordAgent* password_agent_;
  class RenderFrame {
  public:
    class RenderView {
    public:
      class WebView {
      public:
        void advanceFocus(bool reverse);
      };
      WebView* GetWebView();
    };
    RenderView* GetRenderView();
  };
  RenderFrame* render_frame();
  void OnPasswordAccepted(const base::string16& password);
};