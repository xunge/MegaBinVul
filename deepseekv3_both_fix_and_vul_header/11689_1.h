#include <stdio.h>
#include <stdbool.h>

class EmbFile {
public:
    struct {
        bool isStream();
        void streamReset();
        int streamGetChar();
    } m_objStr;

    bool save2(FILE *f);
};

#define unlikely(x) (x)