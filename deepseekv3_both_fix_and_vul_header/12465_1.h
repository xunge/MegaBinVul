#include <mutex>
#include <vector>

class lcPiecesLibrary {
public:
    ~lcPiecesLibrary();
    void WaitForLoadQueue();
    void Unload();
    void ReleaseBuffers();

private:
    std::mutex mLoadMutex;
    std::vector<int> mLoadQueue;
    bool mCancelLoading;
};