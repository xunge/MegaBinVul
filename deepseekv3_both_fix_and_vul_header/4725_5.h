#include <memory>
#include <vector>
#include <string>

namespace blink {
class WebFormElement {
 public:
  bool isNull() const;
};

class WebFormControlElement {
 public:
  bool isNull() const;
  std::string nameForAutofill() const;
  blink::WebFormElement form() const;
};

class WebInputElement : public WebFormControlElement {
 public:
  bool isNull() const;
  std::string nameForAutofill() const;
  blink::WebFormElement form() const;
};

class WebDocument {
 public:
  class All {};
  bool isNull() const;
  All all() const;
};

class WebFrame {
 public:
  blink::WebDocument document() const;
};
}  // namespace blink

class PasswordForm {
 public:
  ~PasswordForm();
};

template <typename T>
class linked_ptr {
 public:
  explicit linked_ptr(T* ptr) : ptr_(ptr) {}
  T* get() const { return ptr_; }
  operator T*() const { return ptr_; }

 private:
  T* ptr_;
};

template <typename T>
linked_ptr<T> make_linked_ptr(T* ptr) {
  return linked_ptr<T>(ptr);
}

class AccountCreationFormData {
 public:
  AccountCreationFormData(linked_ptr<PasswordForm> password_form,
                        const std::vector<blink::WebInputElement>& elements);
};

class PasswordGenerationAgent {
 protected:
  blink::WebInputElement last_focused_password_element_;
  blink::WebInputElement generation_element_;
  std::unique_ptr<AccountCreationFormData> generation_form_data_;
  bool is_manually_triggered_;

  class RenderFrame {
   public:
    blink::WebFrame* GetWebFrame() const;
  };
  RenderFrame* render_frame();
  void ShowGenerationPopup();
  void OnUserTriggeredGeneratePassword();
};

namespace form_util {
std::vector<blink::WebFormControlElement> ExtractAutofillableElementsInForm(
    const blink::WebFormElement& form);
std::vector<blink::WebFormControlElement> GetUnownedFormFieldElements(
    const blink::WebDocument::All& all,
    void*);
}  // namespace form_util

std::unique_ptr<PasswordForm> CreatePasswordFormFromWebForm(
    const blink::WebFormElement& form, void*, void*);
std::unique_ptr<PasswordForm> CreatePasswordFormFromUnownedInputElements(
    const blink::WebFrame& frame, void*, void*);
void GetAccountCreationPasswordFields(
    const std::vector<blink::WebFormControlElement>& control_elements,
    std::vector<blink::WebInputElement>* password_elements);
std::vector<blink::WebInputElement> FindPasswordElementsForGeneration(
    const std::vector<blink::WebInputElement>& password_elements,
    const std::string& name);