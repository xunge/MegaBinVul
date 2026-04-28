#include <stdlib.h>

typedef struct TfLiteIntArray {
  int size;
  int data[];
} TfLiteIntArray;

static inline int TfLiteIntArrayGetSizeInBytes(int size) {
  return sizeof(TfLiteIntArray) + sizeof(int) * size;
}