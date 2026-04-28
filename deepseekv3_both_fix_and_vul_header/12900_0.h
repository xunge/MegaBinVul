#include <stdint.h>

struct PaddingValues {
  int width;
  int height;
  int depth;
};

struct Conv3DTransposeParams {
  int stride_width;
  int stride_height;
  int stride_depth;
  PaddingValues padding_values;
  int dilation_width;
  int dilation_height;
  int dilation_depth;
  float float_activation_min;
  float float_activation_max;
};

class RuntimeShape {
 public:
  RuntimeShape() : size_(0) {}
  explicit RuntimeShape(int dimensions_count) : size_(dimensions_count) {}
  int DimensionsCount() const { return size_; }
  int Dims(int i) const { return 0; }
  int FlatSize() const { return 0; }

 private:
  int size_;
};

inline int MatchingDim(const RuntimeShape& shape1, int index1,
                      const RuntimeShape& shape2, int index2) {
  return 0;
}

inline int Offset(const RuntimeShape& shape, int i0, int i1, int i2, int i3, int i4) {
  return 0;
}

inline float ActivationFunctionWithMinMax(float x, float min, float max) {
  return 0.0f;
}

#define TFLITE_DCHECK_EQ(a, b)