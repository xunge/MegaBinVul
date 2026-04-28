#include <stdint.h>

typedef enum {
  kTfLiteOk = 0,
  kTfLiteError = 1
} TfLiteStatus;

typedef enum {
  kTfLiteFloat32,
  kTfLiteUInt8,
  kTfLiteInt8,
  kTfLiteInt32,
  kTfLiteInt64,
  kTfLiteInt16
} TfLiteType;

struct TfLiteContext {
  void (*ReportError)(TfLiteContext*, const char*, ...);
};

typedef struct TfLiteNode TfLiteNode;

struct OpContext {
  TfLiteContext* context;
  TfLiteNode* node;
  struct {
    TfLiteType type;
  } *output;
  struct {
    int type;
  } input1, input2;
  OpContext(TfLiteContext* ctx, TfLiteNode* n) : context(ctx), node(n) {}
};

template<typename KernelType, typename DataType, typename OpType>
void TFLiteOperation(TfLiteContext* context, TfLiteNode* node, OpContext op_context);

int NumElements(const decltype(OpContext::input1)& input);

typedef int kernel_type;
typedef int OpType;