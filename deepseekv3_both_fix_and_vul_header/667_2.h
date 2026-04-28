#include <vector>
#include <cstdbool>

struct Size {
    int width;
    int height;
};

class FileNodeIterator {
public:
    FileNodeIterator& operator>>(int&);
    FileNodeIterator& operator>>(float&);
    FileNodeIterator& operator>>(double&);
    FileNodeIterator& operator>>(bool&);
};

class FileNode {
public:
    bool empty() const;
    bool isMap() const;
    bool isSeq() const;
    FileNodeIterator begin() const;
    FileNode operator[](const char*);
    template<typename T> FileNode& operator>>(T&);
};

class HOGDescriptor {
public:
    Size winSize;
    Size blockSize;
    Size blockStride;
    Size cellSize;
    int nbins;
    int derivAperture;
    double winSigma;
    int histogramNormType;
    double L2HysThreshold;
    bool gammaCorrection;
    int nlevels;
    bool signedGradient;

    void setSVMDetector(const std::vector<float>&);
    bool read(FileNode& obj);
};

#define CV_Assert(expr) ((void)0)