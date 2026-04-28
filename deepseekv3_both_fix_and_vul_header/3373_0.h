#include <stddef.h>

typedef unsigned int SkColor;

namespace content {
class WebContents;
}

class ColorChooserWin {
public:
    static ColorChooserWin* Open(content::WebContents* web_contents, SkColor initial_color);
    ColorChooserWin(content::WebContents* web_contents, SkColor initial_color);

private:
    static ColorChooserWin* current_color_chooser_;
};