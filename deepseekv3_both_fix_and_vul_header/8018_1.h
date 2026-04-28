#include <unistd.h>
#include <fcntl.h>

typedef int status_t;
#define NO_ERROR 0
#define BAD_VALUE (-1)

typedef struct native_handle {
    int numFds;
    int numInts;
    int data[0];
} native_handle;

native_handle* native_handle_create(int numFds, int numInts);
void native_handle_close(native_handle* h);
void native_handle_delete(native_handle* h);

class Parcel {
public:
    status_t readInt32(int* value) const;
    int readFileDescriptor() const;
    status_t read(void* data, size_t len) const;
    native_handle* readNativeHandle() const;
};