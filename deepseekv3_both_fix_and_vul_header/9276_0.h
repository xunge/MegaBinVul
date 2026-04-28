#include <map>
#include <memory>

class CFFL_ComboBox {
public:
    ~CFFL_ComboBox();
    
private:
    std::map<int, std::unique_ptr<class CFX_FocusHandler>> m_Maps;
    class CFX_FontMap* m_pFontMap;
};

class CFX_FocusHandler {
public:
    void InvalidateFocusHandler(CFFL_ComboBox* pComboBox);
};

class CFX_FontMap {};