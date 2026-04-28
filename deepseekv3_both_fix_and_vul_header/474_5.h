#include <vector>
#include <memory>

class FeatureEvaluator {
public:
    static bool read(const struct FileNode&, struct Size);
};

struct FileNode {
    size_t size() const;
    struct FileNodeIterator begin() const;
};

struct FileNodeIterator {
    FileNodeIterator& operator++();
    FileNode operator*() const;
};

struct Size {
    int width;
    int height;
    Size() : width(0), height(0) {}
    Size(int w, int h) : width(w), height(h) {}
    int area() const { return width * height; }
};

struct Rect {
    int x;
    int y;
    int width;
    int height;
    Rect() : x(0), y(0), width(0), height(0) {}
    Rect(int _x, int _y, int _w, int _h) : x(_x), y(_y), width(_w), height(_h) {}
};

struct Feature {
    bool tilted;
    bool read(const FileNode&);
    bool read(const FileNode&, Size);
};

struct OptFeature {};

namespace ocl {
    bool isOpenCLActivated();
    struct Device {
        static Device getDefault();
        bool isAMD() const;
        bool isIntel() const;
        bool isNVidia() const;
    };
}

template<typename T>
class Ptr {
public:
    T* operator->() { return ptr.get(); }
    T& operator*() { return *ptr; }
    void release() { ptr.reset(); }
    bool empty() const { return !ptr; }
    template<typename U>
    Ptr(const std::shared_ptr<U>& p) : ptr(p) {}
private:
    std::shared_ptr<T> ptr;
};

template<typename T>
Ptr<T> makePtr() {
    return Ptr<T>(std::make_shared<T>());
}

template<>
class Ptr<void> {
public:
    void release() { ptr.reset(); }
    bool empty() const { return !ptr; }
    template<typename U>
    Ptr(const std::shared_ptr<U>& p) : ptr(p) {}
private:
    std::shared_ptr<void> ptr;
};

class HaarEvaluator {
public:
    bool read(const FileNode& node, Size _origWinSize);
    Ptr<std::vector<Feature>> features;
    Ptr<std::vector<OptFeature>> optfeatures;
    Ptr<std::vector<OptFeature>> optfeatures_lbuf;
    bool hasTiltedFeatures;
    Size sbufSize;
    Size localSize;
    Size lbufSize;
    Size origWinSize;
    Rect normrect;
    int nchannels;
    Ptr<void> ufbuf;
};

#define CV_Assert(expr)