#include <cstdint>
#include <iostream>
#include <string>

enum DataType {
  DT_STRING
};

class TensorKey {
public:
  DataType dtype() const;
  bool shape() const;
  bool tensor_data() const;
  int64_t NumElements() const;
  template <typename T> T unaligned_flat() const;
};

class tstring {
public:
  bool operator!=(const tstring& other) const;
  const tstring& operator()(int64_t) const;
};

bool DataTypeCanUseMemcpy(DataType dtype);
const char* DataTypeString(DataType dtype);

#define TF_PREDICT_FALSE(x) (x)
#define DCHECK(condition) \
  if (!(condition))       \
  std::cerr