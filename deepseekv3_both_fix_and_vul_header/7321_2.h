#include <string.h>
#include <stdlib.h>

struct json_t;
typedef struct json_t json_t;
typedef json_t json_auto_t;

struct tang_keys_info {
    json_t* m_keys;
    json_t* m_rotated_keys;
    json_t* m_sign;
    json_t* m_payload;
};

const char** supported_hashes(void);
char* jwk_thumbprint(json_t* jwk, const char* hash);
int jwk_valid_for_deriving_keys(json_t* jwk);
int jwk_valid_for_signing(json_t* jwk);
json_t* jwk_sign(json_t* payload, json_t* sign);
void cleanup_str(char** str);
json_t* json_deep_copy(json_t* json);
int json_array_extend(json_t* array, json_t* other);
#define json_array_foreach(array, index, value) \
    for(index = 0; index < json_array_size(array); index++) \
        if((value = json_array_get(array, index)))
int json_array_append(json_t* array, json_t* value);
json_t* json_incref(json_t* json);
size_t json_array_size(json_t* array);
json_t* json_array_get(json_t* array, size_t index);