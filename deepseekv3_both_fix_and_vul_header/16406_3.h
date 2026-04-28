#include <memory>
#include <mutex>

class SQLiteDBInstance {
public:
    SQLiteDBInstance(void* db);
    SQLiteDBInstance(void* db, std::mutex& mutex);
    bool isPrimary() const;
};

using SQLiteDBInstanceRef = std::shared_ptr<SQLiteDBInstance>;

class SQLiteDBManager {
public:
    static SQLiteDBManager& instance();
    SQLiteDBInstanceRef getConnection(bool primary);
    std::mutex create_mutex_;
    void* db_ = nullptr;
    SQLiteDBInstanceRef connection_;
    std::mutex mutex_;
};

class WriteLock {
public:
    WriteLock(std::mutex& mutex) : mutex_(mutex) {}
private:
    std::mutex& mutex_;
};

void openOptimized(void*& db);
void attachVirtualTables(const SQLiteDBInstanceRef& instance);