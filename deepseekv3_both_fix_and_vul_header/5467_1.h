#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

typedef int status_t;
#define NO_MEMORY (-1)
#define BAD_TYPE (-2)
#define BAD_VALUE (-3)
#define NO_ERROR (0)

typedef struct native_handle {
    int version;
    int numFds;
    int numInts;
    int data[0];
} native_handle;

native_handle* native_handle_create(int numFds, int numInts);
void free_handle();

#define ALOGE(...)

class GraphicBuffer {
public:
    int width;
    int height;
    int stride;
    int format;
    int usage;
    native_handle* handle;
    uint64_t mId;
    bool mOwner;
    bool ownHandle;

    class BufferMapper {
    public:
        status_t registerBuffer(native_handle* handle);
    } mBufferMapper;

    status_t unflatten(void const*& buffer, size_t& size, int const*& fds, size_t& count);
};