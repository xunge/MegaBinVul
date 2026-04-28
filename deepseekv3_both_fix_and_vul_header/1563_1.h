#include <stdint.h>

typedef enum {
  kTfLiteFloat32,
  kTfLiteInt8,
} TfLiteType;

typedef enum {
  kTfLiteOk,
  kTfLiteError,
} TfLiteStatus;

typedef struct TfLiteContext TfLiteContext;

struct TfLiteEvalTensor {
  TfLiteType type;
};

typedef int32_t IndicesT;

const char* TfLiteTypeGetName(TfLiteType type);

#define TF_LITE_KERNEL_LOG(context, ...)

template <typename T, typename IndicesT>
TfLiteStatus GatherNd(const TfLiteEvalTensor* params,
                      const TfLiteEvalTensor* indices,
                      TfLiteEvalTensor* output);