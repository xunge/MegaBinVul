#include <atomic>

struct ThreadPoolProvider {
    void finish();
};

struct ThreadPool {
    struct Data {
        std::atomic<ThreadPoolProvider*> provider;
        ~Data();
    };
};