#include <cstdint>

struct DuelPlayer {
    int type;
};

class TagDuel {
public:
    void UpdateDeck(DuelPlayer* dp, void* pdata, unsigned int len);
};

struct STOC_ErrorMsg {
    int msg;
    int code;
};

namespace BufferIO {
    int ReadInt32(char*&);
};

namespace NetServer {
    void SendPacketToPlayer(DuelPlayer*, int, STOC_ErrorMsg);
};

class deckManager {
public:
    static bool LoadDeck(void*, int*, int, int);
};

extern bool ready[4];
extern bool deck_error[4];
extern void* pdeck[4];

const int ERRMSG_DECKERROR = 0;
const int STOC_ERROR_MSG = 0;

extern deckManager deckManager;