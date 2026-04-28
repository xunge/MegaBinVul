#include <memory>
#include <cassert>

template<typename K, typename V> class WillBeHeapHashMap;
template<typename T> class RefPtrWillBeMember;
template<typename T> class RawPtrWillBeMember;

class MutationObserver {
public:
    enum MutationType {
        Attributes
    };
};

typedef int MutationRecordDeliveryOptions;

class QualifiedName;

class ScriptForbiddenScope {
public:
    ScriptForbiddenScope() {}
};

class Node {
public:
    Node* parentNode();
    WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>& mutationObserverRegistry();
    WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>& transientMutationObserverRegistry();
    
    void getRegisteredMutationObserversOfType(WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, MutationObserver::MutationType, const QualifiedName*);
    void getRegisteredMutationObserversOfType(WillBeHeapHashMap<RawPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, MutationObserver::MutationType, const QualifiedName*);
    
    void collectMatchingObserversForMutation(WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, 
                                           WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&,
                                           Node&, MutationObserver::MutationType, const QualifiedName*);
    void collectMatchingObserversForMutation(WillBeHeapHashMap<RawPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&, 
                                           WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>&,
                                           Node&, MutationObserver::MutationType, const QualifiedName*);
};

#define ASSERT(expr) assert(expr)