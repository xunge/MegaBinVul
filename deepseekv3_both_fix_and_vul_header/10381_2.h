struct cygsidlist {
    cygsidlist& operator*=(const cygsidlist&);
    cygsidlist& operator+=(const void*);
};

struct user_groups {
    struct {
        int count();
        void** sids;
    } sgsids;
    void* pgsid;
};

typedef void* PSID;
typedef void* PTOKEN_GROUPS;
typedef struct { long long LowPart; long long HighPart; } LUID;

extern cygsidlist well_known_world_sid;
extern cygsidlist well_known_authenticated_users_sid;

void get_token_group_sidlist(cygsidlist&, PTOKEN_GROUPS);
void get_token_group_sidlist(cygsidlist&, PTOKEN_GROUPS, LUID, int&);
void get_server_groups(cygsidlist&, PSID);