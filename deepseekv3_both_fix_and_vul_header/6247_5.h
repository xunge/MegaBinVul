#include <vector>
#include <iterator>

class ShapedType {
public:
    int getRank() const;
};

class Type {
public:
    template<typename T>
    T cast() const;
};

class Value {
public:
    Type getType() const;
};

class DenseElementsAttr {
public:
    template<typename T>
    std::vector<T> getValues() const;
    int getNumElements() const;
};

template<typename T, unsigned N>
class SmallVector {
public:
    SmallVector(typename std::vector<T>::iterator begin,
               typename std::vector<T>::iterator end);
    T operator[](int index) const;
};

// Specialization for cast<ShapedType>()
template<>
ShapedType Type::cast<ShapedType>() const;