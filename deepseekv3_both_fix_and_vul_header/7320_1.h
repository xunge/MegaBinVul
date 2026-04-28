#include <stdlib.h>

typedef struct json_t json_t;
typedef struct json_auto_t json_auto_t;

struct tang_keys_info {
    json_t* m_payload;
    json_t* m_sign;
};

json_t* jwk_sign(json_t* payload, json_t* sign);
json_t* find_by_thp(struct tang_keys_info* tki, const char* thp);
json_t* json_incref(json_t* json);