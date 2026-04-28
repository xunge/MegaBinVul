#include <stdlib.h>
#include <stddef.h>

typedef void* AACENCODER;
AACENCODER mAACEncoder;
void* mInputFrame;

class SoftAACEncoder2 {
public:
    ~SoftAACEncoder2();
};

void aacEncClose(AACENCODER* encoder);
void onReset();