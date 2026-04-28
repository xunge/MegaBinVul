#include <stdint.h>
#include <vector>

typedef int32_t status_t;
#define INVALID_OPERATION (-1)

struct MediaBuffer {};

template<typename T>
class Vector : public std::vector<T> {};

struct Track {
    struct Source {
        status_t setBuffers(Vector<MediaBuffer *> &buffers) { return 0; }
    } *mSource;
};

class NuPlayer {
public:
    class GenericSource {
    private:
        bool mIsSecure;
        bool mIsWidevine;
        Track mVideoTrack;
    public:
        status_t setBuffers(bool audio, Vector<MediaBuffer *> &buffers);
    };
};