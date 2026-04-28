#include <vector>
#include <memory>

class SMILTimeContainer {
public:
    bool isStarted();
    void begin();
};

class SVGSVGElement {
public:
    SMILTimeContainer* timeContainer();
};

template<typename T>
class RefPtrWillBeMember {
public:
    T* operator->() const { return ptr; }
    T* ptr;
};

template<typename T>
class WillBeHeapVector : public std::vector<T> {
public:
    void appendRange(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
        this->insert(this->end(), begin, end);
    }
};

class SVGDocumentExtensions {
public:
    void startAnimations();
protected:
    WillBeHeapVector<RefPtrWillBeMember<SVGSVGElement>> m_timeContainers;
};