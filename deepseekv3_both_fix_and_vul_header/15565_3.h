#include <cstddef>
#include <utility>
#include <iostream>

namespace gfx {
class Size {
public:
    Size();
    Size(int width, int height);
};
}  // namespace gfx

namespace base {
class UnsafeSharedMemoryRegion {
public:
    class Mapping {
    public:
        bool IsValid() const;
        size_t size() const;
        Mapping();
        Mapping(Mapping&&);
        Mapping& operator=(Mapping&&);
    };
    Mapping Map() const;
};
}  // namespace base

namespace viz {
enum class SinglePlaneFormat { kRGBA_8888 };
class ResourceSizes {
public:
    static bool MaybeSizeInBytes(const gfx::Size& size,
                                SinglePlaneFormat format,
                                size_t* bytes);
};
}  // namespace viz

class CefLayeredWindowUpdaterOSR {
public:
    void OnAllocatedSharedMemory(const gfx::Size& pixel_size,
                               base::UnsafeSharedMemoryRegion region);
protected:
    gfx::Size pixel_size_;
    base::UnsafeSharedMemoryRegion::Mapping shared_memory_;
};

#define DCHECK(condition)
#define DLOG(severity) std::cerr
#define ERROR 0