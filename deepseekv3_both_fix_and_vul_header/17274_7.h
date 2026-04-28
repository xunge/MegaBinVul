#include <cassert>
#include <cstring>

#define NULLP nullptr

namespace Image {
    class Sampled {
    public:
        using dimen_t = int;
        dimen_t wd;
        dimen_t ht;
    };

    class Indexed : public Sampled {
    public:
        using slen_t = int;
        int cpp;
        char* headp;
        char* rowbeg;
        signed int transp;
        unsigned char getNcols();
        void to8();
        void setTransp(int);
        Indexed** separate();
        Indexed(dimen_t, dimen_t, int, int);
    };
}