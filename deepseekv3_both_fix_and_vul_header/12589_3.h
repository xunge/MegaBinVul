#include <stdint.h>
#include <stddef.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteFloat32 = 1,
  kTfLiteInt8 = 9,
  kTfLiteInt32 = 3
} TfLiteType;

typedef enum {
  kTfLiteArenaRw,
  kTfLiteArenaRwPersistent
} TfLiteAllocationType;

typedef struct TfLiteIntArray {
  int size;
  int data[1];
} TfLiteIntArray;

typedef struct TfLiteAffineQuantization {
  TfLiteIntArray* scale;
  TfLiteIntArray* zero_point;
} TfLiteAffineQuantization;

typedef struct TfLiteQuantizationParams {
  float scale;
  int32_t zero_point;
} TfLiteQuantizationParams;

typedef struct TfLiteQuantization {
  void* params;
  void* quantized_dimension;
} TfLiteQuantization;

typedef struct TfLiteTensor {
  TfLiteType type;
  TfLiteAllocationType allocation_type;
  TfLiteIntArray* dims;
  TfLiteQuantization quantization;
  void* data;
} TfLiteTensor;

typedef struct TfLiteContext {
  TfLiteStatus (*ResizeTensor)(struct TfLiteContext*, TfLiteTensor*, TfLiteIntArray*);
} TfLiteContext;

typedef struct TfLiteNode {
  void* builtin_data;
  void* user_data;
  TfLiteIntArray* inputs;
  TfLiteIntArray* outputs;
  TfLiteIntArray* temporaries;
} TfLiteNode;

typedef struct TfLiteSVDFParams {
  int rank;
} TfLiteSVDFParams;

typedef struct OpData {
  int scratch_tensor_index;
  bool compute_row_sums;
  int32_t effective_scale_1_a;
  int32_t effective_scale_1_b;
  int32_t effective_scale_2_a;
  int32_t effective_scale_2_b;
} OpData;

#define TF_LITE_ENSURE_EQ(context, a, b) ((a == b) ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE(context, condition) (condition ? kTfLiteOk : kTfLiteError)
#define TF_LITE_ENSURE_OK(context, status) (status)

enum {
  kInputTensor = 0,
  kWeightsFeatureTensor = 1,
  kWeightsTimeTensor = 2,
  kBiasTensor = 3,
  kStateTensor = 4,
  kOutputTensor = 0
};

static inline int NumDimensions(const TfLiteTensor* t) { return t->dims->size; }
static inline int SizeOfDimension(const TfLiteTensor* t, int dim) { return t->dims->data[dim]; }
static inline bool TfLiteIntArrayEqual(const TfLiteIntArray* a, const TfLiteIntArray* b) { return false; }
static inline bool TfLiteIntArrayEqualsArray(const TfLiteIntArray* a, int b_size, const int b_data[]) { return false; }
static inline TfLiteIntArray* TfLiteIntArrayCopy(const TfLiteIntArray* src) { return NULL; }
static inline void TfLiteIntArrayFree(TfLiteIntArray* a) {}

static TfLiteStatus GetInputSafe(TfLiteContext* context, TfLiteNode* node, int index, const TfLiteTensor** tensor) { return kTfLiteOk; }
static TfLiteStatus GetOutputSafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }
static TfLiteStatus GetTemporarySafe(TfLiteContext* context, TfLiteNode* node, int index, TfLiteTensor** tensor) { return kTfLiteOk; }
static const TfLiteTensor* GetOptionalInputTensor(TfLiteContext* context, TfLiteNode* node, int index) { return NULL; }
static bool IsHybridOp(const TfLiteTensor* input, const TfLiteTensor* weights_feature) { return false; }
static void QuantizeMultiplier(double scale, int32_t* multiplier, int32_t* shift) {}

static TfLiteIntArray* TfLiteIntArrayCreate(int size) { return NULL; }