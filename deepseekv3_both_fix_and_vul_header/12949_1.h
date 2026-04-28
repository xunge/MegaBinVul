#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned char UBYTE;
typedef unsigned short UWORD;
typedef long LONG;

struct Line {
    LONG *m_pData;
    struct Line *m_pNext;
};

class SingleComponentLSScan {
public:
    bool ParseMCU(void);
};