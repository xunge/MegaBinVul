#include <stdlib.h>
#include <string.h>

typedef struct SFG_MenuEntry SFG_MenuEntry;
typedef struct SFG_Menu SFG_Menu;
typedef struct SFG_Structure SFG_Structure;
typedef struct SFG_State SFG_State;
typedef struct SFG_Node SFG_Node;

struct SFG_Node {
    SFG_Node *next;
    SFG_Node *prev;
};

struct SFG_MenuEntry {
    char *Text;
    SFG_Menu *SubMenu;
    int ID;
    SFG_Node Node;
};

struct SFG_Menu {
    SFG_Node Entries;
};

struct SFG_Structure {
    SFG_Menu *CurrentMenu;
};

struct SFG_State {
    int ActiveMenus;
};

extern SFG_Structure fgStructure;
extern SFG_State fgState;

#define FGAPIENTRY
#define FREEGLUT_EXIT_IF_NOT_INITIALISED(x)
#define freeglut_return_if_fail(x)

SFG_Menu* fgMenuByID(int id);
void fgListAppend(SFG_Node *list, SFG_Node *node);
void fghCalculateMenuBoxSize(void);
void fgError(const char *msg);