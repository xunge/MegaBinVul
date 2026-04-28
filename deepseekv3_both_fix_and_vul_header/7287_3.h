#include <vector>
#include <cstdint>
#include <cstring>

namespace cricket {
    enum MediaType {
        MEDIA_TYPE_AUDIO,
        MEDIA_TYPE_VIDEO,
        MEDIA_TYPE_DATA
    };
}

namespace rtc {
    template <typename T>
    class ArrayView {
    public:
        ArrayView(T* data, size_t size) : data_(data), size_(size) {}
        ArrayView() : data_(nullptr), size_(0) {}
        T* data() const { return data_; }
        size_t size() const { return size_; }
    private:
        T* data_;
        size_t size_;
    };

    template <typename T>
    class ArrayView<const T> {
    public:
        ArrayView(const T* data, size_t size) : data_(data), size_(size) {}
        ArrayView() : data_(nullptr), size_(0) {}
        const T* data() const { return data_; }
        size_t size() const { return size_; }
    private:
        const T* data_;
        size_t size_;
    };
}

class CbrDetectorRemote {
public:
    enum class Status {
        kOk,
        kError
    };

    struct Result {
        Result(Status status, uint32_t length) : status(status), length(length) {}
        Status status;
        uint32_t length;
    };

    static uint32_t frame_size;
    static uint32_t frame_count;
    static uint32_t missmatch_count;
    static bool detected;
    static constexpr uint32_t MIN_MATCH = 200;
    static constexpr uint32_t MAX_MISSMATCH = 10;

    static void info(const char* message);
    static Result Decrypt(cricket::MediaType media_type,
                         const std::vector<uint32_t>& csrcs,
                         rtc::ArrayView<const uint8_t> additional_data,
                         rtc::ArrayView<const uint8_t> encrypted_frame,
                         rtc::ArrayView<uint8_t> frame);
};

uint32_t CbrDetectorRemote::frame_size = 0;
uint32_t CbrDetectorRemote::frame_count = 0;
uint32_t CbrDetectorRemote::missmatch_count = 0;
bool CbrDetectorRemote::detected = false;