#include <cstdint>
#include <vector>
#include <memory>

struct Buffer {
    struct RawSlice {
        void* mem_;
        size_t len_;
    };
    
    struct Instance {
        uint64_t length() const;
        std::vector<RawSlice> getRawSlices() const;
    };
};

class Runtime {
public:
    static bool runtimeFeatureEnabled(const char* feature);
};

class Stats {
public:
    struct {
        void inc();
    } zstd_dictionary_error_, zstd_generic_error_;
};

class DDictManager {
public:
    void* getDictionaryById(uint32_t id);
};

enum LogLevel {
    trace
};

#define ENVOY_LOG(level, ...)

class ZstdDecompressorImpl {
public:
    void decompress(const Buffer::Instance& input_buffer, Buffer::Instance& output_buffer);
private:
    bool is_dictionary_set_;
    uint32_t dictionary_id_;
    Stats stats_;
    struct ZSTD_DCtx_s {};
    std::unique_ptr<ZSTD_DCtx_s> dctx_;
    DDictManager* ddict_manager_;

    void setInput(const Buffer::RawSlice& input_slice);
    bool process(Buffer::Instance& output_buffer);
    bool isError(size_t result);
    
    static uint32_t ZSTD_getDictID_fromFrame(const void* src, size_t srcSize);
    static size_t ZSTD_DCtx_refDDict(ZSTD_DCtx_s* dctx, void* ddict);
};

constexpr uint64_t MaxInflateRatio = 100;