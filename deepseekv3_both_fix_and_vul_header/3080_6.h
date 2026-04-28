#include <stddef.h>

class MutationObserverRegistration;

template<typename T> class OwnPtr {
public:
    OwnPtr(T*);
    T* get() const;
    operator T*() const;
    bool operator==(const OwnPtr&) const;
};

template<typename T> class Vector {
public:
    size_t find(const T&) const;
    void remove(size_t);
};

class Node {
public:
    Vector<OwnPtr<MutationObserverRegistration>>* mutationObserverRegistry();
    void unregisterMutationObserver(MutationObserverRegistration*);
};

template<typename T> class RefPtr {
public:
    RefPtr(T*);
};

#define ASSERT(expr) ((void)0)
const size_t notFound = static_cast<size_t>(-1);