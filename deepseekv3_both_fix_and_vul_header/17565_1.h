#include <cstddef>
#include <cstring>
#include <algorithm>

#define DASSERT(expr) ((void)0)
#define YYMAXFILL 0

class Scanner {
private:
    bool eof;
    char *bot;
    char *tok;
    char *lim;
    size_t BSIZE;

    void pop_finished_files();
    void shift_ptrs_and_fpos(ptrdiff_t offset);
    void shift_ptrs_and_fpos(char *new_bot);
    bool read(size_t free);
    void fatal(const char *msg);
public:
    bool fill(size_t need);
};