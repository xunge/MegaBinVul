#include <stdbool.h>
#include <string>

enum StyleDifference {
    StyleDifferenceLayout
};

namespace RenderStyleConstants {
    enum WhiteSpace { PRE };
}

class RenderStyle {
public:
    RenderStyleConstants::WhiteSpace whiteSpace() const;
};

class RenderSVGInlineText;

class RenderText {
public:
    void styleDidChange(StyleDifference diff, const RenderStyle* oldStyle);
};

class RenderSVGText {
public:
    static RenderSVGText* locateRenderSVGTextAncestor(RenderSVGInlineText*);
    void setNeedsLayout();
    void subtreeStyleDidChange(RenderSVGInlineText*);
};

class RenderSVGInlineText : public RenderText {
public:
    void styleDidChange(StyleDifference diff, const RenderStyle* oldStyle);
    void updateScaledFont();
    const RenderStyle* style() const;
    std::string originalText() const;
    void setText(const std::string& text, bool preserve);
    std::string applySVGWhitespaceRules(const std::string& text, bool preserve);
    static constexpr auto PRE = RenderStyleConstants::PRE;
};