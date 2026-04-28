#include <string>

class RenderCounter {
public:
    void updateCounter();
    void setText(const std::string& text);
    void setTextInternal(const std::string& text);
    std::string originalText();
};