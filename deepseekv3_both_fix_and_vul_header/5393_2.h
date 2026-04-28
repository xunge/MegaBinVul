#include <vector>

class RenderTableSection;
class RenderTableCaption;

class RenderTable {
public:
    void simplifiedNormalFlowLayout();
protected:
    std::vector<RenderTableCaption*> m_captions;
    RenderTableSection* topSection();
    RenderTableSection* sectionBelow(RenderTableSection*);
};

class RenderTableSection {
public:
    void layoutIfNeeded();
    void computeOverflowFromCells();
};

class RenderTableCaption {
public:
    void layoutIfNeeded();
};