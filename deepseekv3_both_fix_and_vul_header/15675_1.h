#include <stdlib.h>
#include <string.h>

typedef struct SFG_Node SFG_Node;
typedef struct SFG_MenuEntry SFG_MenuEntry;
typedef struct SFG_List SFG_List;
typedef struct SFG_Menu SFG_Menu;
typedef struct SFG_State SFG_State;

struct SFG_Node {
    SFG_Node *Next;
    SFG_Node *Prev;
};

struct SFG_MenuEntry {
    char *Text;
    int ID;
    SFG_Node Node;
};

struct SFG_List {
    SFG_Node *First;
    SFG_Node *Last;
};

struct SFG_Menu {
    SFG_List Entries;
};

struct SFG_State {
    int ActiveMenus;
};

extern SFG_State fgState;
extern struct SFG_Structure {
    SFG_Menu *CurrentMenu;
} fgStructure;

#define FGAPIENTRY
#define FREEGLUT_EXIT_IF_NOT_INITIALISED(x)
#define freeglut_return_if_fail(x)
#define fgError(x)
#define fgListAppend(x, y)
#define fghCalculateMenuBoxSize()