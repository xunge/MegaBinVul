#include <stddef.h>

typedef int MutationRecordDeliveryOptions;
typedef int QualifiedName;

template<typename T>
class RawPtrWillBeMember {
public:
    RawPtrWillBeMember(T*);
};

template<typename T>
class RefPtrWillBeMember {
public:
    RefPtrWillBeMember(T*);
};

template<typename K, typename V>
class WillBeHeapHashMap {
public:
    bool isEmpty() const;
};

class MutationObserver {
public:
    enum MutationType {
        Attributes
    };
};

class Node {
public:
    void getRegisteredMutationObserversOfType(WillBeHeapHashMap<RawPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, MutationObserver::MutationType, const QualifiedName*);
    void getRegisteredMutationObserversOfType(WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, MutationObserver::MutationType, const QualifiedName*);
};

template<typename T>
class adoptPtrWillBeNoop;

template<typename T>
class PassOwnPtrWillBeRawPtr {
public:
    PassOwnPtrWillBeRawPtr(T*);
    PassOwnPtrWillBeRawPtr(const adoptPtrWillBeNoop<T>&);
};

template<typename T>
class adoptPtrWillBeNoop {
public:
    adoptPtrWillBeNoop(T*);
};

class MutationObserverInterestGroup {
public:
    static PassOwnPtrWillBeRawPtr<MutationObserverInterestGroup> createIfNeeded(Node&, MutationObserver::MutationType, MutationRecordDeliveryOptions, const QualifiedName*);
    MutationObserverInterestGroup(WillBeHeapHashMap<RawPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>, MutationRecordDeliveryOptions);
    MutationObserverInterestGroup(WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>, MutationRecordDeliveryOptions);
};

#define ASSERT(expr)