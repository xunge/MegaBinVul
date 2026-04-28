#include <map>
#include <vector>
#include <memory>

#define ASSERT(expr) ((void)0)

class DatabaseContext {
public:
    void stopDatabases();
};

template<typename T>
class Member : public std::shared_ptr<T> {
public:
    using std::shared_ptr<T>::shared_ptr;
};

template<typename T>
class Vector : public std::vector<T> {
public:
    using std::vector<T>::vector;
};

template<typename Key, typename Value>
class HashMap : public std::map<Key, Value> {
public:
    using std::map<Key, Value>::map;
    bool isEmpty() const { return this->empty(); }
    size_t size() const { return std::map<Key, Value>::size(); }
    Vector<Value> values() const {
        Vector<Value> result;
        for (const auto& pair : *this)
            result.push_back(pair.second);
        return result;
    }
};

class DatabaseManager {
public:
    static DatabaseManager* s_databaseManager;
    HashMap<int, Member<DatabaseContext>> m_contextMap;
    static bool isMainThread();
    void terminateDatabaseThread();
};

DatabaseManager* DatabaseManager::s_databaseManager = nullptr;