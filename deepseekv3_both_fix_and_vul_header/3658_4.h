#include <stdint.h>
#include <algorithm>
#include <cassert>

#define DCHECK(condition) assert(condition)
#define DCHECK_EQ(val1, val2) assert((val1) == (val2))

struct AVCodecContext {
    int width;
    int height;
    int pix_fmt;
    int coded_width;
    int coded_height;
    int lowres;
    struct {
        int num;
        int den;
    } sample_aspect_ratio;
};

struct AVFrame {
    uint8_t* data[4];
    uint8_t* base[4];
    int linesize[4];
    void* opaque;
    int type;
    int width;
    int height;
    int format;
};

#define AVERROR(e) (-(e))
#define EINVAL 22
#define FF_BUFFER_TYPE_USER 1

struct gfx {
    struct Size {
        int width_;
        int height_;
        Size() : width_(0), height_(0) {}
        Size(int w, int h) : width_(w), height_(h) {}
        int width() const { return width_; }
        int height() const { return height_; }
    };
    struct Rect {
        Rect(const Size& size) {}
    };
};

class VideoFrame {
public:
    enum Format {
        UNKNOWN,
        YV12,
        YV16,
        YV12J
    };
    static bool IsValidConfig(Format format, const gfx::Size& coded_size, const gfx::Rect& visible_rect, const gfx::Size& natural_size) { return true; }
    uint8_t* data(int plane) { return nullptr; }
    int stride(int plane) { return 0; }
};

template<typename T>
class scoped_refptr {
    T* ptr;
public:
    scoped_refptr(T* frame = nullptr) : ptr(frame) {}
    T* operator->() { return ptr; }
    void swap(T** other) { std::swap(ptr, *other); }
};

class FFmpegVideoDecoder {
public:
    int GetVideoBuffer(AVCodecContext* codec_context, AVFrame* frame);
private:
    struct Config {
        gfx::Size natural_size() const { return gfx::Size(0,0); }
    } config_;
    class FramePool {
    public:
        scoped_refptr<VideoFrame> CreateFrame(VideoFrame::Format format, const gfx::Size& coded_size, const gfx::Rect& visible_rect, const gfx::Size& natural_size, int64_t timestamp) {
            return scoped_refptr<VideoFrame>(nullptr);
        }
    } frame_pool_;
};

inline int av_image_check_size(int width, int height, int log_offset, void* log_ctx) {
    return 0;
}

inline gfx::Size GetNaturalSize(const gfx::Size& size, int num, int den) {
    return gfx::Size(0, 0);
}

inline int64_t kNoTimestamp() {
    return 0;
}

inline VideoFrame::Format PixelFormatToVideoFormat(int pix_fmt) {
    return VideoFrame::UNKNOWN;
}