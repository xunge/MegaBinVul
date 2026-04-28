#include <string>
#include <string_view>

namespace base {
using string16 = std::u16string;
}

namespace blink {
class WebFormControlElement {
public:
    void setValue(const base::string16& value, bool send_events);
    void setAutofilled(bool autofilled);
    base::string16 value() const;
    void setSelectionRange(int start, int end);
    class Document {
    public:
        class Frame {
        public:
            void unmarkText();
        };
        Frame* frame();
    };
    Document document();
};
class WebInputElement : public WebFormControlElement {
public:
    void setChecked(bool checked, bool send_events);
    int maxLength() const;
};
}

using blink::WebInputElement;

struct FormFieldData {
    base::string16 value;
    bool is_autofilled;
    bool is_checked;
};

blink::WebInputElement* toWebInputElement(blink::WebFormControlElement*);
bool IsCheckableElement(blink::WebInputElement*);
bool IsTextInput(blink::WebInputElement*);
bool IsMonthInput(blink::WebInputElement*);
bool IsTextAreaElement(const blink::WebFormControlElement&);
void TruncateString(base::string16*, int);