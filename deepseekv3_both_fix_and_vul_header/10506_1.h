#include <stddef.h>

#define VO_ERR_NONE 0
#define CHECK_EQ(a, b) ((a) == (b))

struct SoftAACEncoder {
    void onReset();
    void* mEncoderHandle;
    struct {
        int Uninit(void*);
    } *mApiHandle;
    void* mMemOperator;
    char* mInputFrame;
    ~SoftAACEncoder();
};