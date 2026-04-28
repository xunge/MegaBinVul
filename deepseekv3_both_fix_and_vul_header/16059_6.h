#include <cstdint>

struct DuelPlayer {
    int type;
    unsigned char state;
};

struct STOC_ErrorMsg {
    int msg;
    int code;
};

class BufferIO {
public:
    static int ReadInt32(char*& buf);
};

class NetServer {
public:
    static void SendPacketToPlayer(DuelPlayer* dp, int type, const STOC_ErrorMsg& msg);
    static void SendPacketToPlayer(DuelPlayer* dp, int type);
};

class DeckManager {
public:
    static bool LoadDeck(void* pdeck, int* deckbuf, int mainc, int sidec);
    static bool LoadSide(void* pdeck, int* deckbuf, int mainc, int sidec);
};

extern DeckManager deckManager;

class SingleDuel {
public:
    void UpdateDeck(DuelPlayer* dp, void* pdata, unsigned int len);
};

enum {
    ERRMSG_DECKERROR,
    ERRMSG_SIDEERROR,
    STOC_ERROR_MSG,
    STOC_DUEL_START,
    STOC_SELECT_TP,
    CTOS_TP_RESULT,
    DUEL_STAGE_FIRSTGO
};

extern bool ready[2];
extern int duel_count;
extern bool deck_error[2];
extern void* pdeck[2];
extern DuelPlayer* players[2];
extern int tp_player;
extern int duel_stage;