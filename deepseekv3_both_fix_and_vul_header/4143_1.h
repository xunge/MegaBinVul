namespace ui {
enum ModalType {
  MODAL_TYPE_NONE,
  MODAL_TYPE_WINDOW,
  MODAL_TYPE_CHILD, 
  MODAL_TYPE_SYSTEM
};
}

class ExtensionInstallDialogView {
public:
  ui::ModalType GetModalType() const;
private:
  class Prompt {
  public:
    bool ShouldUseTabModalDialog() const;
  };
  Prompt* prompt_;
};