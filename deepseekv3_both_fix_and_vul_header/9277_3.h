#include <map>
#include <memory>

class Invalidator {
public:
    void InvalidateFocusHandler(class CFFL_TextField* pHandler);
};

class FontMap {
public:
    ~FontMap();
};

struct CFFL_TextField {
    std::map<int, std::unique_ptr<Invalidator>> m_Maps;
    FontMap* m_pFontMap;
    ~CFFL_TextField();
};