#include <stddef.h>

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;