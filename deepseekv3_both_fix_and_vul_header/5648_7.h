#include <memory>
#include <vector>

template<typename T> class PassRefPtr {
public:
    PassRefPtr(T* ptr);
    T* get();
};

template<typename T> class RefPtr {
public:
    RefPtr(T* ptr);
    T* get();
};

template<typename T> class SkAutoTUnref {
public:
    SkAutoTUnref(T* ptr);
    operator T*() const;
    T* get();
};

template<typename T> PassRefPtr<T> adoptRef(T* ptr);

class SkImageFilter {
public:
    struct CropRect {};
};

class SkColorFilter {};

class SkColorFilterImageFilter {
public:
    static SkImageFilter* Create(SkColorFilter*, SkImageFilter*, const SkImageFilter::CropRect*);
};

class SkiaImageFilterBuilder {
public:
    SkImageFilter* build(SkImageFilter*, const char*);
    float* cropOffset();
};

class FEColorMatrix {
public:
    enum Type {};
    SkColorFilter* createColorFilter(Type, const float*);
    SkColorFilter* createColorFilter(Type, const std::vector<float>&);
    SkImageFilter::CropRect getCropRect(const float*);
    SkImageFilter* inputEffect(int);
    const char* operatingColorSpace();
    PassRefPtr<SkImageFilter> createImageFilter(SkiaImageFilterBuilder*);
private:
    Type m_type;
    std::vector<float> m_values;
};