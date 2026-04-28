#include <stddef.h>

typedef unsigned MutationRecordDeliveryOptions;
class MutationObserver {
public:
    enum MutationType {};
};
class Node;
class QualifiedName;
class Registry {
public:
    struct Registration {
        bool shouldReceiveMutationFrom(Node&, MutationObserver::MutationType, const QualifiedName*);
        MutationRecordDeliveryOptions deliveryOptions();
        MutationObserver& observer();
    };
    Registration** begin();
    Registration** end();
};

template<typename T> class RawPtrWillBeMember {
public:
    RawPtrWillBeMember(T*);
    operator T*() const;
    T* operator->() const;
    T* get() const;
};

template<typename T> class RefPtrWillBeMember {
public:
    RefPtrWillBeMember(T*);
    operator T*() const;
    T* operator->() const;
    T* get() const;
};

template<typename K, typename V> class WillBeHeapHashMap {
public:
    class AddResult {
    public:
        bool isNewEntry;
        struct {
            V value;
        }* storedValue;
    };
    AddResult add(const K&, V);
};