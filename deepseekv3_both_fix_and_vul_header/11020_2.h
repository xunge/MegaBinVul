#include <assert.h>
#include <stdlib.h>

struct z_stream;
struct ZlibInStream {
    z_stream* zs;
    void setUnderlying(void*, int);
    void removeUnderlying();
    void deinit();
};

int inflateEnd(z_stream*);