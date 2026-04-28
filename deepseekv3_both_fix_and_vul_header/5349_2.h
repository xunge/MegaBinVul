#include <map>
#include <utility>

class IndexedDBDispatcherHost {
public:
    ~IndexedDBDispatcherHost();
private:
    std::map<int, std::pair<void*, bool>> blob_data_handle_map_;
};

template <typename T>
void STLDeleteValues(T* container) {
    for (auto it = container->begin(); it != container->end(); ++it) {
        delete it->second.first;
    }
    container->clear();
}