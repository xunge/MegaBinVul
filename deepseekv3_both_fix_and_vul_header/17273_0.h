#include <stdlib.h>

#define NULLP 0

namespace Image {
    class Indexed {
    public:
        static void delete_separated(void* imgs);
    };

    class SampledInfo {
    public:
        ~SampledInfo();
        void* img;
        void* imgs;
    };
}