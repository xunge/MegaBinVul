#include <stdbool.h>

typedef void* PSID;
typedef void* PTOKEN_GROUPS;
typedef unsigned long LUID;

struct cygsidlist {
    cygsidlist& operator*=(const cygsidlist&);
    cygsidlist& operator+=(PSID);
    bool operator==(PSID) const;
    bool operator!=(PSID) const;
};

extern cygsidlist well_known_world_sid;
extern cygsidlist well_known_authenticated_users_sid;
extern cygsidlist well_known_system_sid;

bool get_token_group_sidlist(cygsidlist&, PTOKEN_GROUPS);
bool get_token_group_sidlist(cygsidlist&, PTOKEN_GROUPS, LUID, int&);
bool get_server_groups(cygsidlist&, PSID);