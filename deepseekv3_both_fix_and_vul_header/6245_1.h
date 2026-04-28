#include <stddef.h>

#define nullptr NULL

typedef struct TfLiteContext TfLiteContext;
typedef struct TfLiteNode TfLiteNode;
typedef struct TfLiteTensor TfLiteTensor;

struct TfLiteTensor {
  int is_variable;
};

TfLiteTensor* GetMutableInput(TfLiteContext* context, const TfLiteNode* node, int index);