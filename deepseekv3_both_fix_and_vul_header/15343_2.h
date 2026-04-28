#include <mutex>
#include <memory>
#include <vector>

class MetaDataBase {
public:
    void clear();
protected:
    struct InternalData {
        std::mutex mLock;
        std::vector<int> mItems;
    };
    std::shared_ptr<InternalData> mInternalData;
};