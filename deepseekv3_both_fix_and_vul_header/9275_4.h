#include <map>

class CPWL_Wnd;
class CFFL_FormFiller;

struct CFFL_PrivateData {};

class CPWL_Wnd {
public:
    void* GetAttachedData();
    void Destroy();
    void InvalidateProvider(CFFL_FormFiller* provider);
};

class CFFL_FormFiller {
public:
    ~CFFL_FormFiller();
protected:
    std::map<int, CPWL_Wnd*> m_Maps;
};