#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

#define CV_32F 5
#define CV_32FC2 13
#define CV_Error(code, msg) throw std::runtime_error(msg)

using std::vector;
using std::max;
using std::min;

struct Size {
    int width;
    int height;
};

class UMat {
public:
    int cols;
    int rows;
    int depth();
    int channels();
    void setTo(float value);
    Size size();
    UMat& getMat(int access);
};

class InputArray {
public:
    UMat getUMat();
    Size size();
    bool sameSize(class InputOutputArray arr);
    int depth();
    int channels();
};

class InputOutputArray {
public:
    UMat& getUMatRef();
    void create(Size size, int type);
    bool sameSize(InputArray arr);
    int depth();
    int channels();
};

class VariationalRefinement {
public:
    void calcUV(UMat I0, UMat I1, UMat Ux, UMat Uy);
};

class DISOpticalFlowImpl {
public:
    bool ocl_calc(InputArray I0, InputArray I1, InputOutputArray flow);

private:
    int coarsest_scale;
    int finest_scale;
    int patch_size;
    int patch_stride;
    int variational_refinement_iter;
    vector<UMat> u_I0s;
    vector<UMat> u_I1s;
    vector<UMat> u_I1s_ext;
    vector<UMat> u_I0xs;
    vector<UMat> u_I0ys;
    vector<UMat> u_Ux;
    vector<UMat> u_Uy;
    UMat u_Sx;
    UMat u_Sy;
    UMat u_U;
    UMat u_I0xx_buf;
    UMat u_I0yy_buf;
    UMat u_I0xy_buf;
    UMat u_I0x_buf;
    UMat u_I0y_buf;
    int w;
    int h;
    int ws;
    int hs;
    vector<VariationalRefinement*> variational_refinement_processors;

    void autoSelectPatchSizeAndScales(int width);
    bool ocl_prepareBuffers(UMat I0, UMat I1, UMat flow, bool use_input_flow);
    bool ocl_precomputeStructureTensor(UMat I0xx_buf, UMat I0yy_buf, UMat I0xy_buf, UMat I0x_buf, UMat I0y_buf, UMat I0x, UMat I0y);
    bool ocl_PatchInverseSearch(UMat Ux, UMat Uy, UMat I0, UMat I1_ext, UMat I0x, UMat I0y, int search_iters, int scale);
    bool ocl_Densification(UMat Ux, UMat Uy, UMat Sx, UMat Sy, UMat I0, UMat I1);
};

enum AccessFlag {
    ACCESS_WRITE
};

void resize(UMat src, UMat dst, Size size);
void multiply(UMat src, float scale, UMat dst);
void merge(const vector<UMat>& src, UMat dst);