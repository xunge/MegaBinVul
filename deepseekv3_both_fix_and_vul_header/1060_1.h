#define TFLITE_DCHECK_EQ(a, b) ((void)0)

inline float ActivationFunctionWithMinMax(float x, float min, float max) {
  return x < min ? min : x > max ? max : x;
}