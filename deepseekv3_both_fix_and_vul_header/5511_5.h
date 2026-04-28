#include <memory>
#include <functional>
#include <stdint.h>

#define CHECK(expr) (void)(expr)

enum vpx_img_fmt {
  VPX_IMG_FMT_I420,
  VPX_IMG_FMT_YV12,
  VPX_IMG_FMT_I444
};

enum vpx_plane {
  VPX_PLANE_Y,
  VPX_PLANE_U,
  VPX_PLANE_V
};

struct vpx_image {
  vpx_img_fmt fmt;
  int d_w;
  int d_h;
  int stride[4];
  uint8_t* planes[4];
  void* fb_priv;
};

namespace gfx {
  struct Size {
    Size(int w, int h) {}
  };
  struct Rect {
    Rect(const Size& size) {}
  };
}

class VideoFrame {
public:
  enum Format {
    YV12,
    YV12A,
    YV24
  };
  static std::shared_ptr<VideoFrame> WrapExternalYuvData(
      Format format,
      const gfx::Size& coded_size,
      const gfx::Rect& visible_rect,
      const gfx::Size& natural_size,
      int32_t y_stride,
      int32_t u_stride,
      int32_t v_stride,
      uint8_t* y_data,
      uint8_t* u_data,
      uint8_t* v_data,
      int64_t timestamp,
      std::function<void()> no_longer_needed_cb);
};

template <typename T>
using scoped_refptr = std::shared_ptr<T>;

class TimeDelta {
public:
  operator int64_t() const { return 0; }
  static TimeDelta kNoTimestamp() { return TimeDelta(); }
};

class MemoryPool {
public:
  std::function<void()> CreateFrameCallback(void* fb_priv);
};

class FramePool {
public:
  scoped_refptr<VideoFrame> CreateFrame(
      VideoFrame::Format format,
      const gfx::Size& coded_size,
      const gfx::Rect& visible_rect,
      const gfx::Size& natural_size,
      TimeDelta timestamp);
};

class Config {
public:
  gfx::Size natural_size() const { return gfx::Size(0, 0); }
};

class VpxVideoDecoder {
public:
  void CopyVpxImageTo(const vpx_image* vpx_image,
                     const struct vpx_image* vpx_image_alpha,
                     scoped_refptr<VideoFrame>* video_frame);
  
  void CopyYPlane(const uint8_t* src_y, int stride_y, int rows, VideoFrame* dst);
  void CopyUPlane(const uint8_t* src_u, int stride_u, int rows, VideoFrame* dst);
  void CopyVPlane(const uint8_t* src_v, int stride_v, int rows, VideoFrame* dst);
  void CopyAPlane(const uint8_t* src_a, int stride_a, int rows, VideoFrame* dst);
  void MakeOpaqueAPlane(int stride_a, int rows, VideoFrame* dst);

  TimeDelta kNoTimestamp() { return TimeDelta::kNoTimestamp(); }

private:
  bool vpx_codec_alpha_;
  std::unique_ptr<MemoryPool> memory_pool_;
  FramePool frame_pool_;
  Config config_;
};