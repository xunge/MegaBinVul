#include <cstdint>
#include <string>

enum class TType {
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
  void readBool(bool&);
  void readByte(int8_t&);
  void readI16(int16_t&);
  void readI32(int32_t&);
  void readI64(int64_t&);
  void readDouble(double&);
  void readFloat(float&);
  void readBinary(std::string&);
  void readStructBegin(std::string&);
  void readFieldBegin(std::string&, TType&, int16_t&);
  void readFieldEnd();
  void readStructEnd();
  void readMapBegin(TType&, TType&, uint32_t&);
  void readMapEnd();
  void readSetBegin(TType&, uint32_t&);
  void readSetEnd();
  void readListBegin(TType&, uint32_t&);
  void readListEnd();
};

namespace apache { namespace thrift {
  void skip(Protocol_& prot, TType arg_type);
}}

class TProtocolException {
public:
  static void throwInvalidSkipType(TType arg_type);
};