#include <memory>
#include <vector>
#include <string>
#include <iostream>

class PasswordForm {
public:
    std::string signon_realm;
};

class GaiaUrls {
public:
    static GaiaUrls* GetInstance();
    std::string gaia_login_form_realm();
};

namespace blink {
class WebFormElement {
public:
    bool isNull() const;
};
class WebInputElement {};
template <typename T> class WebVector {
public:
    size_t size() const;
    T& operator[](size_t);
};
class WebFrame {
public:
    class Document {
    public:
        void forms(WebVector<WebFormElement>&);
    };
    Document& document();
};
}

class GURL {
public:
    GURL(const std::string&);
    bool operator==(const GURL&) const;
};

template <typename T> class linked_ptr {
public:
    linked_ptr(T*);
};

template <typename T> linked_ptr<T> make_linked_ptr(T*);

class AccountCreationFormData {
public:
    AccountCreationFormData(linked_ptr<PasswordForm>, const std::vector<blink::WebInputElement>&);
};

namespace form_util {
std::vector<blink::WebInputElement> ExtractAutofillableElementsInForm(const blink::WebFormElement&);
}

#define VLOG(x) std::cout

class PasswordGenerationAgent {
protected:
    bool enabled_;
    class RenderFrame {
    public:
        class WebFrame {
        public:
            blink::WebFrame* GetWebFrame();
            blink::WebFrame::Document& document();
        };
        WebFrame* GetWebFrame();
    };
    RenderFrame* render_frame();
    bool ShouldAnalyzeDocument();
    void* generation_form_data_;
    std::vector<AccountCreationFormData> possible_account_creation_forms_;
    PasswordForm* CreatePasswordFormFromWebForm(const blink::WebFormElement&, void*, void*);
    bool GetAccountCreationPasswordFields(const std::vector<blink::WebInputElement>&, std::vector<blink::WebInputElement>*);
    void DetermineGenerationElement();
    void FindPossibleGenerationForm();
};