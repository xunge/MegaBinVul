#include <algorithm>
#include <cstdint>

#define TFLITE_DCHECK_EQ(a, b) ((void)0)

struct RuntimeShape {
  int Dims(int index) const;
};