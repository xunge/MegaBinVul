#include <stdio.h>
#include <string.h>

#define SLAPI_DSE_CALLBACK_OK 0
#define SLAPI_SEARCH_SCOPE 0
#define SLAPI_SEARCH_ATTRS 0
#define SLAPI_RESULT_TEXT 0
#define SLAPI_PB_RESULT_TEXT 0
#define LDAP_SCOPE_BASE 0
#define LDAP_SUCCESS 0

#define CONFIG_FLAG_ALWAYS_SHOW 0x01
#define CONFIG_FLAG_PREVIOUSLY_SET 0x02

struct berval {
    char *bv_val;
    size_t bv_len;
};

struct ldbminfo {
    void *li_config_mutex;
};

typedef struct config_info {
    const char *config_name;
    unsigned int config_flags;
} config_info;

typedef struct Slapi_PBlock Slapi_PBlock;
typedef struct Slapi_Entry Slapi_Entry;

extern config_info *ldbm_config;
extern int ldbm_config_moved_attr(char *attr);
extern void ldbm_config_get(void *li, config_info *config, char *buf);
extern void PR_Lock(void *mutex);
extern void PR_Unlock(void *mutex);
extern void slapi_pblock_get(Slapi_PBlock *pb, int type, void *out);
extern void slapi_pblock_set(Slapi_PBlock *pb, int type, const char *text);
extern void slapi_entry_attr_replace(Slapi_Entry *e, const char *attr, struct berval **vals);