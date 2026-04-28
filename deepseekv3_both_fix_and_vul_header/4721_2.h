#include <string>
#include <stdint.h>

struct FormData {
  std::string form;
};

struct gfx {
  struct RectF {};
};

class RenderView {
public:
  gfx::RectF ElementBoundsInWindow(void* element);
};

class RenderFrame {
public:
  RenderView* GetRenderView();
};

struct AutofillHostMsg_ShowPasswordEditingPopup {
  AutofillHostMsg_ShowPasswordEditingPopup(int routing_id, 
                                         const gfx::RectF& bounds,
                                         const FormData& form);
};

class PasswordGenerationAgent {
public:
  void ShowEditingPopup();
protected:
  int routing_id_;
  bool editing_popup_shown_;
  RenderFrame* render_frame_;
  void* generation_element_;
  struct {
    FormData* form;
  } *generation_form_data_;

  int routing_id() { return routing_id_; }
  RenderFrame* render_frame() { return render_frame_; }
  void Send(AutofillHostMsg_ShowPasswordEditingPopup* msg);
};