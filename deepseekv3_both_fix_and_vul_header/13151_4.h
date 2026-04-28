#include <cstdint>
#include <functional>
#include <string>
#include <algorithm>
#include <iostream>

using std::string;

typedef uint8_t uint8;
typedef uint8_t GifByteType;

#define WARNING 0
#define LOG(severity) std::cerr

struct InputBufferInfo {
  const uint8_t* data;
  int size;
};

struct GifColorType {
  uint8_t Red;
  uint8_t Green;
  uint8_t Blue;
};

struct ColorMapObject {
  int ColorCount;
  GifColorType* Colors;
};

struct GifImageDesc {
  int Left;
  int Top;
  int Width;
  int Height;
  ColorMapObject* ColorMap;
};

struct SavedImage {
  GifImageDesc ImageDesc;
  uint8_t* RasterBits;
};

struct GraphicsControlBlock {
  int TransparentColor;
};

struct GifFileType {
  int Error;
  int ImageCount;
  SavedImage* SavedImages;
  ColorMapObject* SColorMap;
};

#define D_GIF_SUCCEEDED 0
#define GIF_OK 0

extern "C" {
int input_callback(GifFileType* gif_file, uint8_t* buf, int len);
GifFileType* DGifOpen(void* userPtr, int (*readFunc)(GifFileType*, uint8_t*, int), int* error);
int DGifCloseFile(GifFileType* gif_file, int* error_code);
int DGifSlurp(GifFileType* gif_file);
int DGifSavedExtensionToGCB(GifFileType* gif_file, int frame_index, GraphicsControlBlock* gcb);
}

namespace gtl {
template <typename F>
class Cleanup {
 public:
  explicit Cleanup(F f) : f_(f) {}
  ~Cleanup() { f_(); }
 private:
  F f_;
};

template <typename F>
Cleanup<F> MakeCleanup(F f) {
  return Cleanup<F>(f);
}
}  // namespace gtl

namespace absl {
template <typename... Args>
string StrCat(const Args&... args) { return string(); }
}  // namespace absl

const char* GifErrorStringNonNull(int error_code);