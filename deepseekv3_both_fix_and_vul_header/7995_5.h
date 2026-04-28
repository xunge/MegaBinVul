#include <vector>

typedef int status_t;

struct MediaBuffer {
    virtual status_t setBuffers(std::vector<MediaBuffer*>& buffers);
};

template<typename T>
using Vector = std::vector<T>;

class NuPlayer {
public:
    class GenericSource {
    public:
        status_t setBuffers(bool audio, Vector<MediaBuffer*>& buffers);
    private:
        bool mIsWidevine;
        bool mIsSecure;
        struct {
            MediaBuffer* mSource;
        } mVideoTrack;
    };
};

constexpr status_t INVALID_OPERATION = -1;