#include <utility>
#include <memory>
#include <cassert>

template<typename T> class RefPtrWillBeMember;
template<typename T> class RawPtrWillBeMember;

template<typename K, typename V>
class WillBeHeapHashMap {
public:
    bool isEmpty() const { return false; }
    template<typename OtherK>
    void swap(WillBeHeapHashMap<OtherK, V>& other) {}
};

enum MutationRecordDeliveryOptions {};

class MutationObserver {};

class MutationObserverInterestGroup {
public:
    MutationObserverInterestGroup(WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>& observers, MutationRecordDeliveryOptions oldValueFlag);
    MutationObserverInterestGroup(WillBeHeapHashMap<RawPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions>& observers, MutationRecordDeliveryOptions oldValueFlag);

private:
    MutationRecordDeliveryOptions m_oldValueFlag;
    WillBeHeapHashMap<RefPtrWillBeMember<MutationObserver>, MutationRecordDeliveryOptions> m_observers;
};

#define ASSERT(x) assert(x)