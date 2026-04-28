#include <limits.h>

#define DCHECK(condition) ((void)0)
#define DCHECK_NE(a, b) ((void)0)

class ResourceProvider {
public:
    void InitializeSoftware();
private:
    int thread_checker_;
    int default_resource_type_;
    int max_texture_size_;
    int best_texture_format_;
    void CleanUpGLIfNeeded();
};

enum {
    Bitmap,
    RGBA_8888
};