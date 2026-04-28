#include <cstddef>
#include <iostream>

enum DataType {
  DT_FLOAT,
  DT_DOUBLE,
  DT_INT32,
  DT_UINT8,
  DT_INT16,
  DT_INT8,
  DT_COMPLEX64,
  DT_INT64,
  DT_BOOL,
  DT_QINT8,
  DT_QUINT8,
  DT_QINT32,
  DT_QINT16,
  DT_QUINT16,
  DT_UINT16,
  DT_COMPLEX128,
  DT_HALF,
  DT_INVALID,
  DT_STRING,
  DT_BFLOAT16
};

class TensorSliceWriter {
public:
  static size_t MaxBytesPerElement(DataType dt);
  static size_t MaxBytesPerElementOrZero(DataType dt);
};

#define LOG(severity) std::cerr
#define FATAL ""