#include <string>

struct Rect {};
struct FormData {};
struct GenerationElement {
    int maxLength();
    std::u16string nameForAutofill();
};

class RenderFrame {
public:
    class RenderView* GetRenderView();
};

class RenderView {
public:
    Rect ElementBoundsInWindow(const GenerationElement& element);
};

struct AutofillHostMsg_ShowPasswordGenerationPopup {
    AutofillHostMsg_ShowPasswordGenerationPopup(
        int routing_id,
        const Rect& bounds,
        int max_length,
        const std::u16string& name,
        bool is_manually_triggered,
        const FormData& form);
};

class PasswordGenerationAgent {
public:
    int routing_id();
    RenderFrame* render_frame();
    void Send(AutofillHostMsg_ShowPasswordGenerationPopup* msg);
    void ShowGenerationPopup();
    
    GenerationElement generation_element_;
    struct {
        FormData* form;
    } *generation_form_data_;
    bool is_manually_triggered_;
    bool generation_popup_shown_;
};