#include <cstdint>
#include <string>

enum TType {
  T_STOP,
  T_BOOL,
  T_BYTE,
  T_I16,
  T_I32,
  T_I64,
  T_DOUBLE,
  T_FLOAT,
  T_STRING,
  T_STRUCT,
  T_MAP,
  T_SET,
  T_LIST
};

class Protocol_ {
public:
  uint32_t readBool(bool&);
  uint32_t readByte(int8_t&);
  uint32_t readI16(int16_t&);
  uint32_t readI32(int32_t&);
  uint32_t readI64(int64_t&);
  uint32_t readDouble(double&);
  uint32_t readFloat(float&);
  uint32_t readBinary(std::string&);
  uint32_t readStructBegin(std::string&);
  uint32_t readFieldBegin(std::string&, TType&, int16_t&);
  uint32_t readFieldEnd();
  uint32_t readStructEnd();
  uint32_t readMapBegin(TType&, TType&, uint32_t&, bool&);
  bool peekMap();
  uint32_t readMapEnd();
  uint32_t readSetBegin(TType&, uint32_t&, bool&);
  bool peekSet();
  uint32_t readSetEnd();
  uint32_t readListBegin(TType&, uint32_t&, bool&);
  bool peekList();
  uint32_t readListEnd();
};

class TProtocolException {
public:
  static void throwInvalidSkipType(TType);
};