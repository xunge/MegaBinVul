#include <vector>

class Gfx {
private:
    std::vector<int> stateGuards;
    bool subPage;
    class OutputDev {
    public:
        void endPage();
    } *out;
    class Resources {
    public:
        Resources* res;
    } *res;
    class GfxState {
    public:
        bool hasSaves();
    } *state;
    class MarkedContent {
    public:
        MarkedContent* mcStack;
    } *mcStack;
    
public:
    ~Gfx();
    void popStateGuard();
    void error(int code, const char* msg);
    void restoreState();
    void popResources();
    void popMarkedContent();
};