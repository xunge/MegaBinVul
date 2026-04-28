#include <cstdint>

class cygsidlist {
public:
    cygsidlist& operator+=(const cygsidlist&);
    cygsidlist& operator+=(const void*);  // For SID* addition
    cygsidlist& operator*=(const cygsidlist&);
    int count() const;
};

struct wincap_t {
    bool has_console_logon_sid() const;
} wincap;

struct LUID {
    uint32_t LowPart;
    int32_t HighPart;
};

typedef unsigned long DWORD;
#define SE_GROUP_LOGON_ID (0xC0000000)

struct SID;
struct TOKEN_GROUPS {
    DWORD GroupCount;
    struct {
        SID* Sid;
        DWORD Attributes;
    } Groups[1];
};
typedef TOKEN_GROUPS* PTOKEN_GROUPS;

extern cygsidlist well_known_local_sid;
extern cygsidlist well_known_console_logon_sid;
extern cygsidlist well_known_dialup_sid;
extern cygsidlist well_known_network_sid;
extern cygsidlist well_known_batch_sid;
extern cygsidlist well_known_interactive_sid;
extern cygsidlist well_known_service_sid;
extern cygsidlist well_known_this_org_sid;
extern cygsidlist well_known_users_sid;

bool sid_in_token_groups(PTOKEN_GROUPS, const cygsidlist&);
long long get_ll(LUID);