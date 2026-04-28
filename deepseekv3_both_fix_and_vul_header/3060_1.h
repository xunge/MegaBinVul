#include <stdlib.h>

class InlineTextBox {
public:
    void dirtyLineBoxes();
    InlineTextBox* nextTextBox();
};

class SVGInlineTextBox : public InlineTextBox {
public:
    void dirtyLineBoxes();
    void clearTextFragments();
};