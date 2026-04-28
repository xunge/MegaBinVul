#include <math.h>
#include <stddef.h>

typedef double MagickRealType;
typedef unsigned int Quantum;
typedef struct _RandomInfo RandomInfo;

#define QuantumRange 4294967295.0
#define QuantumScale (1.0/QuantumRange)
#define MagickPI 3.14159265358979323846264338327950288419716939937510
#define MagickEpsilon 1.0e-10

typedef enum
{
  UndefinedEvaluateOperator,
  AbsEvaluateOperator,
  AddEvaluateOperator,
  AddModulusEvaluateOperator,
  AndEvaluateOperator,
  CosineEvaluateOperator,
  DivideEvaluateOperator,
  ExponentialEvaluateOperator,
  GaussianNoiseEvaluateOperator,
  ImpulseNoiseEvaluateOperator,
  LaplacianNoiseEvaluateOperator,
  LeftShiftEvaluateOperator,
  LogEvaluateOperator,
  MaxEvaluateOperator,
  MeanEvaluateOperator,
  MedianEvaluateOperator,
  MinEvaluateOperator,
  MultiplicativeNoiseEvaluateOperator,
  MultiplyEvaluateOperator,
  OrEvaluateOperator,
  PoissonNoiseEvaluateOperator,
  PowEvaluateOperator,
  RightShiftEvaluateOperator,
  RootMeanSquareEvaluateOperator,
  SetEvaluateOperator,
  SineEvaluateOperator,
  SubtractEvaluateOperator,
  SumEvaluateOperator,
  ThresholdEvaluateOperator,
  ThresholdBlackEvaluateOperator,
  ThresholdWhiteEvaluateOperator,
  UniformNoiseEvaluateOperator,
  XorEvaluateOperator
} MagickEvaluateOperator;

typedef enum
{
  UndefinedNoise,
  UniformNoise,
  GaussianNoise,
  MultiplicativeGaussianNoise,
  ImpulseNoise,
  LaplacianNoise,
  PoissonNoise
} NoiseType;

extern double EvaluateMax(double,double);
extern double MagickMin(double,double);
extern Quantum GenerateDifferentialNoise(RandomInfo *,Quantum,NoiseType,double);