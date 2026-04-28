#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>

template<typename T> class RefPtrWillBeRawPtr {
public:
    T* get() const { return nullptr; }
    T* operator->() const { return nullptr; }
    operator bool() const { return false; }
    RefPtrWillBeRawPtr() = default;
    RefPtrWillBeRawPtr(std::nullptr_t) {}
    operator T*() const { return nullptr; }
};

template<typename T> class PassRefPtrWillBeRawPtr {
public:
    operator RefPtrWillBeRawPtr<T>() { return RefPtrWillBeRawPtr<T>(); }
    PassRefPtrWillBeRawPtr(RefPtrWillBeRawPtr<T>&) {}
    RefPtrWillBeRawPtr<T> get() { return *this; }
};

class String {
public:
    bool isNull() const { return false; }
};

class MutationRecord {
public:
    static PassRefPtrWillBeRawPtr<MutationRecord> createWithNullOldValue(PassRefPtrWillBeRawPtr<MutationRecord>);
    String oldValue() const;
};

class MutationObserver {
public:
    void enqueueMutationRecord(PassRefPtrWillBeRawPtr<MutationRecord>);
    void enqueueMutationRecord(RefPtrWillBeRawPtr<MutationRecord>);
};

class MutationObserverInterestGroup {
public:
    void enqueueMutationRecord(PassRefPtrWillBeRawPtr<MutationRecord>);
private:
    struct ObserverEntry {
        RefPtrWillBeRawPtr<MutationObserver> key;
        int value;
    };
    std::vector<ObserverEntry> m_observers;
    bool hasOldValue(int);
};