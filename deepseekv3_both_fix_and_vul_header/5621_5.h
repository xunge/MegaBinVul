#include <set>
#include <vector>
#include <cassert>

class ExecutionContext;
class MutationObserverRegistration;

class InspectorInstrumentation {
public:
    static void didClearAllMutationRecords(ExecutionContext*, class MutationObserver*);
};

class MutationObserverRegistration {
public:
    void unregister();
};

template<typename T> class Vector {
public:
    void clear();
};

template<typename T> class HashSet {
public:
    bool contains(const T&) const;
    bool isEmpty() const;
    operator std::set<T>() const { return m_set; }
private:
    std::set<T> m_set;
};

using MutationObserverRegistrationSet = std::set<MutationObserverRegistration*>;

class MutationObserver {
public:
    void disconnect();
    Vector<int> m_records;
    HashSet<MutationObserverRegistration*> m_registrations;
    struct Callback {
        ExecutionContext* executionContext();
    }* m_callback;
};

#define ASSERT(x) assert(x)