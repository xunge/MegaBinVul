#include <vector>
#include <cstddef>
#include <cstdint>

struct Status {
    bool IsFatalError() const;
    operator bool() const;
};

struct BitReader {};

enum FrameEncoding {
    kVarDCT
};

struct FrameHeader {
    enum Flags {
        kPatches,
        kSplines,
        kNoise
    };
    Flags flags;
    int upsampling;
    std::vector<size_t> extra_channel_upsampling;
    FrameEncoding encoding;
};

struct FrameDimensions {
    std::size_t xsize;
    std::size_t ysize;
    std::size_t xsize_padded;
    std::size_t ysize_padded;
    std::size_t xsize_upsampled_padded;
    std::size_t ysize_upsampled_padded;
};

struct ImageFeatures {
    struct {
        Status Decode(BitReader*, std::size_t, std::size_t, bool*);
        void Clear();
    } patches;
    struct {
        Status Decode(BitReader*, std::size_t);
        Status InitializeDrawCache(std::size_t, std::size_t, void*);
        void Clear();
    } splines;
    struct {
    } noise_params;
};

struct Matrices {
    Status DecodeDC(BitReader*);
};

struct PassesSharedState {
    FrameHeader frame_header;
    ImageFeatures image_features;
    Matrices matrices;
};

struct DecodedImage {
    bool IsJPEG();
};

struct DecState {
    PassesSharedState shared_storage;
    struct {
        void* cmap;
    }* shared;
};

struct ModularFrameDecoder {
    Status DecodeGlobalInfo(BitReader*, FrameHeader, bool);
};

struct FrameDecoder {
    Status ProcessDCGlobal(BitReader*);
    FrameDimensions frame_dim_;
    FrameHeader frame_header_;
    DecodedImage* decoded_;
    DecState* dec_state_;
    ModularFrameDecoder modular_frame_decoder_;
    bool decoded_dc_global_;
    bool allow_partial_dc_global_;
    void* pool_;
};

Status DecodeNoise(BitReader*, void*);
namespace jxl {
    Status DecodeGlobalDCInfo(BitReader*, bool, DecState*, void*);
}

#define PROFILER_FUNC
#define JXL_RETURN_IF_ERROR(expr) if (!(expr)) return Status();
#define JXL_FAILURE(msg) Status()