#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define CV_8U 0
#define CV_32F 5
#define CV_32FC2 13
#define CV_Assert(expr) ((void)0)
#define CV_OCL_RUN(cond, func) ((void)0)
#define CV_Error(code, msg) ((void)0)

struct Size {
    int width;
    int height;
};

class Mat {
public:
    int cols;
    int rows;
    int depth() const { return 0; }
    int channels() const { return 0; }
    bool empty() const { return false; }
    bool isContinuous() const { return true; }
    bool sameSize(const Mat& other) const { return true; }
    void setTo(float value) {}
    void create(int rows, int cols, int type) {}
    Mat getMat() const { return *this; }
    Size size() const { return Size{cols, rows}; }
    static void merge(Mat* arr, int count, Mat& dst) {}
    void operator*=(float scale) {}
};

class InputArray {
public:
    bool empty() const { return false; }
    int depth() const { return 0; }
    int channels() const { return 0; }
    bool isContinuous() const { return true; }
    bool sameSize(InputArray arr) const { return true; }
    Mat getMat() const { return Mat(); }
    Size size() const { return Size{0,0}; }
};

class InputOutputArray : public InputArray {
public:
    void create(Size size, int type) {}
    Mat getMat() const { return Mat(); }
};

class Range {
public:
    Range(int start, int end) {}
};

class VariationalRefinement {
public:
    void calcUV(Mat& I0, Mat& I1, Mat& Ux, Mat& Uy) {}
};

template<typename T>
class Ptr {
public:
    T* operator->() { return nullptr; }
};

class DISOpticalFlowImpl;

class PatchInverseSearch_ParBody {
public:
    PatchInverseSearch_ParBody(DISOpticalFlowImpl& impl, int stripes, int hs, 
                              Mat& Sx, Mat& Sy, Mat& Ux, Mat& Uy, Mat& I0s, 
                              Mat& I1s_ext, Mat& I0xs, Mat& I0ys, int mode, int scale);
};

class Densification_ParBody {
public:
    Densification_ParBody(DISOpticalFlowImpl& impl, int stripes, int rows, 
                          Mat& Ux, Mat& Uy, Mat& Sx, Mat& Sy, Mat& I0s, Mat& I1s);
};

class parallel_for_ {
public:
    template<typename Body>
    parallel_for_(Range range, const Body& body) {}
};

class DISOpticalFlowImpl {
protected:
    int patch_size;
    bool use_spatial_propagation;
    int coarsest_scale;
    int finest_scale;
    int patch_stride;
    int variational_refinement_iter;
    vector<Mat> I0s;
    vector<Mat> I1s;
    vector<Mat> I0xs;
    vector<Mat> I0ys;
    vector<Mat> I1s_ext;
    vector<Mat> Ux;
    vector<Mat> Uy;
    Mat U;
    Mat Sx;
    Mat Sy;
    Mat I0xx_buf;
    Mat I0yy_buf;
    Mat I0xy_buf;
    Mat I0x_buf;
    Mat I0y_buf;
    int w;
    int h;
    int ws;
    int hs;
    vector<Ptr<VariationalRefinement>> variational_refinement_processors;

    void ocl_calc(InputArray I0, InputArray I1, InputOutputArray flow) {}
    void prepareBuffers(Mat& I0, Mat& I1, Mat& flow, bool use_input_flow) {}
    void precomputeStructureTensor(Mat& I0xx, Mat& I0yy, Mat& I0xy, Mat& I0x, Mat& I0y, Mat& I0x_aux, Mat& I0y_aux) {}
    void autoSelectPatchSizeAndScales(int original_img_width) {}
    int getNumThreads() { return 1; }
    void resize(Mat& src, Mat& dst, Size size) {}
    static void merge(Mat* arr, int count, Mat& dst) {}

public:
    void calc(InputArray I0, InputArray I1, InputOutputArray flow);
};