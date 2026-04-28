#include <string>
#include <stdexcept>

#define ALWAYS_INLINE inline __attribute__((__always_inline__))

enum KindOf {
  KindOfUninit,
  KindOfNull,
  KindOfBoolean,
  KindOfInt64,
  KindOfDouble,
  KindOfPersistentString,
  KindOfString,
  KindOfClass,
  KindOfLazyClass,
  KindOfResource,
  KindOfFunc,
  KindOfPersistentVec,
  KindOfVec,
  KindOfPersistentDict,
  KindOfDict,
  KindOfPersistentKeyset,
  KindOfKeyset,
  KindOfPersistentDArray,
  KindOfDArray,
  KindOfPersistentVArray,
  KindOfVArray,
  KindOfObject,
  KindOfClsMeth,
  KindOfRClsMeth,
  KindOfRFunc,
  KindOfRecord
};

struct StringData {
  const char* data();
  size_t size();
};

class String;

class StringBuffer {
public:
  void append(const char* str);
  void append(size_t value);
  void append(const char* str, size_t len);
  String detach();
};

class String {
public:
  String(const char* str);
  String(StringBuffer&& sb);
};

class Variant {
public:
  KindOf getType() const;
  StringData* getStringData() const;
  void* toClassVal() const;
  void* toLazyClassVal() const;
};

class SerializeOptions {
public:
  bool keepDVArrays;
  bool forcePHPArrays;
  bool warnOnHackArrays;
  bool warnOnPHPArrays;
  bool ignoreLateInit;
  bool serializeProvenanceAndLegacy;
};

class VariableSerializer {
public:
  enum class Type { Serialize };
  VariableSerializer(Type type);
  void keepDVArrays();
  void setForcePHPArrays();
  void setHackWarn();
  void setPHPWarn();
  void setIgnoreLateInit();
  void setSerializeProvenanceAndLegacy();
  String serialize(const Variant& value, bool b1, bool b2);
};

class Exception : public std::exception {
public:
  Exception(const char* fmt, ...);
};

StringData* classToStringHelper(void* val);
StringData* lazyClassToStringHelper(void* val);

namespace RuntimeOption {
  extern size_t MaxSerializedStringSize;
}

extern String s_Res;

inline bool isStringType(KindOf kind) {
  return kind == KindOfString || kind == KindOfPersistentString;
}

inline bool isClassType(KindOf kind) {
  return kind == KindOfClass;
}