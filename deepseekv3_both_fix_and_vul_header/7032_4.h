#include <sys/stat.h>
#include <string>
#include <vector>
#include <cstdint>

class StringStringEntryProto {
public:
    bool has_key() const;
    bool has_value() const;
    const std::string& key() const;
    const std::string& value() const;
};

class TensorProto {
public:
    enum DataType {
        UNDEFINED,
        FLOAT,
        DOUBLE,
        INT32,
        INT64,
        UINT32,
        UINT64,
        UINT8,
        INT8,
        UINT16,
        INT16,
        BOOL,
        FLOAT16,
        BFLOAT16,
        COMPLEX64,
        COMPLEX128,
        STRING
    };
    
    enum DataLocation {
        EXTERNAL
    };
    
    const std::string& name() const;
    DataType data_type() const;
    bool has_data_type() const;
    bool has_data_location() const;
    DataLocation data_location() const;
    const std::vector<int64_t>& dims() const;
    const std::vector<float>& float_data() const;
    const std::vector<int32_t>& int32_data() const;
    const std::vector<std::string>& string_data() const;
    const std::vector<int64_t>& int64_data() const;
    const std::string& raw_data() const;
    const std::vector<double>& double_data() const;
    const std::vector<uint64_t>& uint64_data() const;
    const std::vector<StringStringEntryProto>& external_data() const;
};

class CheckerContext {
public:
    std::string get_model_dir() const;
};

void enforce_has_field(const TensorProto& tensor, const std::string& field);
void fail_check();
template<typename... Args>
void fail_check(Args&&... args);
std::string clean_relative_path(const std::string& path);
std::string path_join(const std::string& dir, const std::string& rel_path);

static const std::string k_preferred_path_separator = "/";
static const std::string data_type = "data_type";