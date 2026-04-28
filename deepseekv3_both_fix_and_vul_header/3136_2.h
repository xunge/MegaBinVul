#include <stdint.h>

typedef uint32_t SkColor;
extern SkColor g_custom_colors[];

struct RunState {
    int state;
};

class ColorListener {
public:
    virtual void OnColorChosen(SkColor color) = 0;
    virtual void OnColorChooserDialogClosed() = 0;
};

class ColorChooserDialog {
public:
    void DidCloseDialog(bool chose_color, SkColor color, RunState run_state);
private:
    ColorListener* listener_;
    SkColor* custom_colors_;
    void EndRun(RunState run_state);
    void CopyCustomColors(SkColor* src, SkColor* dst);
};