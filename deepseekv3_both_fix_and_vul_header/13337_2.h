#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <string_view>

enum class Result { Ok, Error };
inline bool Succeeded(Result result) { return result == Result::Ok; }
inline Result operator|=(Result& a, Result b) { return a = static_cast<Result>(static_cast<int>(a) | static_cast<int>(b)); }

struct Errors {};
struct Location { enum Type { Binary }; };
struct Module {
    std::string name;
};
struct ReadBinaryOptions {
    ReadBinaryOptions(int features, FILE* log_stream, bool read_debug_names,
                     bool stop_on_first_error, bool fail_on_custom_section_error) {}
};
struct ValidateOptions {
    ValidateOptions(int features) {}
};
struct FileStream {
    FileStream(const char* filename) {}
    FileStream(FILE* file) {}
    FileStream(std::string filename) : FileStream(filename.c_str()) {}
};
struct WriteCOptions {
    std::string module_name;
};

extern std::string s_infile;
extern std::string s_outfile;
extern int s_features;
extern std::unique_ptr<FILE, int(*)(FILE*)> s_log_stream;
extern bool s_read_debug_names;
extern WriteCOptions s_write_c_options;

void InitStdio();
void ParseOptions(int argc, char** argv);
Result wasm2c(Errors& errors);
Result ReadFile(const char* filename, std::vector<uint8_t>* out_data);
Result ReadBinaryIr(const char* filename, const uint8_t* data, size_t size,
                   const ReadBinaryOptions& options, Errors* errors, Module* module);
Result ValidateModule(Module* module, Errors* errors, const ValidateOptions& options);
Result GenerateNames(Module* module);
Result ApplyNames(Module* module);
Result WriteC(FileStream* c_stream, FileStream* h_stream, const char* header_name,
             const Module* module, const WriteCOptions& options);
void FormatErrorsToFile(const Errors& errors, Location::Type location_type);
std::string strip_extension(const std::string& filename);
std::string GetBasename(const std::string& path);
std::string StripExtension(const std::string& filename);

#define WABT_USE(x) (void)(x)