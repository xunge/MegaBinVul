#include <unistd.h>
#include <stdint.h>

typedef int status_t;
#define NO_ERROR 0
#define BAD_VALUE (-1)

typedef struct native_handle {
    int version;
    int numFds;
    int numInts;
    int data[0];
} native_handle;

class Parcel {
public:
    status_t readInt32(int* val) const;
    int readFileDescriptor() const;
    status_t read(void* data, size_t size) const;
    native_handle* readNativeHandle() const;
};

native_handle* native_handle_create(int numFds, int numInts);
void native_handle_close(native_handle* h);
void native_handle_delete(native_handle* h);