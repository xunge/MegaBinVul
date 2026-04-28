#include <functional>
#include <vector>
#include <unordered_set>
#include <memory>

class Database {
public:
    void close();
};

class DatabaseTaskSynchronizer {
public:
    void taskCompleted();
};

class Task {
public:
    Task(std::function<void()>);
};

class DatabaseTaskCoordinator {
public:
    void shutdown();
};

class Thread {
public:
    void postTask(Task*);
};

using DatabaseSet = std::unordered_set<std::shared_ptr<Database>>;

class DatabaseThread {
public:
    DatabaseTaskCoordinator* m_transactionCoordinator;
    DatabaseSet m_openDatabaseSet;
    DatabaseTaskSynchronizer* m_cleanupSync;
    Thread* m_thread;
    
    void cleanupDatabaseThread();
};

namespace WTF {
    template<typename... Args>
    void LOG(const char* channel, const char* format, Args... args);
    
    template<typename F, typename... Args>
    auto bind(F&& f, Args&&... args) {
        return std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    }
}

#define WTF_LOG(channel, format, ...) WTF::LOG(channel, format, ##__VA_ARGS__)
const char* StorageAPI = "StorageAPI";