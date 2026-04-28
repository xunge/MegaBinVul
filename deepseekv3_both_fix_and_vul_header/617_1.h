#include <stdint.h>

struct CUDT;

class CSndUList
{
public:
    void insert_(int64_t ts, const CUDT* u);
private:
    int m_iLastEntry;
    int m_iArrayLength;
    void realloc_();
    void insert_norealloc_(int64_t ts, const CUDT* u);
    void insert_norealloc(int64_t ts, const CUDT* u);
};