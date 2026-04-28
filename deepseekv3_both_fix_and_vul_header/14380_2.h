#include <time.h>
#include <string.h>
#include <stdlib.h>

#define GLEWLWYD_DEFAULT_SESSION_EXPIRATION_COOKIE 3600
#define G_OK 0
#define G_ERROR_UNAUTHORIZED 1
#define G_ERROR_NOT_FOUND 2
#define G_ERROR_PARAM 3
#define Y_LOG_LEVEL_ERROR 0
#define Y_LOG_LEVEL_INFO 1
#define Y_LOG_LEVEL_WARNING 2
#define GLWD_METRICS_AUTH_USER_VALID 0
#define GLWD_METRICS_AUTH_USER_VALID_SCHEME 1
#define GLWD_METRICS_AUTH_USER_INVALID 2
#define GLWD_METRICS_AUTH_USER_INVALID_SCHEME 3
#define U_CALLBACK_CONTINUE 0

struct config_elements {
    char *session_key;
    char *cookie_domain;
    int cookie_secure;
};

struct _u_request {
    struct _u_map *map_header;
    struct _u_map *map_cookie;
};

struct _u_response {
    int status;
};

struct _u_map;

typedef void json_t;

void *ulfius_get_json_body_request(const struct _u_request *request, void *arg);
const char *get_ip_source(const struct _u_request *request);
char *get_client_hostname(const struct _u_request *request);
int json_string_length(json_t *value);
json_t *json_object_get(json_t *object, const char *key);
const char *json_string_value(json_t *string);
int o_strcmp(const char *s1, const char *s2);
json_t *auth_check_user_credentials(struct config_elements *config, const char *username, const char *password);
int check_result_value(json_t *result, int value);
char *get_session_id(struct config_elements *config, const struct _u_request *request);
char *generate_session_id();
int user_session_update(struct config_elements *config, char *session_uid, const char *user_agent, char *issued_for, const char *username, const char *scheme_name, int flag);
void y_log_message(int level, const char *format, ...);
void ulfius_add_cookie_to_response(struct _u_response *response, const char *key, const char *value, const char *expires, int max_age, const char *domain, const char *path, int secure, int http_only);
void o_free(void *ptr);
void glewlwyd_metrics_increment_counter_va(struct config_elements *config, int metric, int value, ...);
int json_is_string(json_t *value);
void ulfius_set_string_body_response(struct _u_response *response, int status, const char *body);
json_t *get_users_for_session(struct config_elements *config, char *session_uid);
const char *u_map_get_case(const struct _u_map *map, const char *key);
const char *u_map_get(const struct _u_map *map, const char *key);
int json_is_object(json_t *value);
json_t *auth_check_user_scheme(struct config_elements *config, const char *scheme_type, const char *scheme_name, const char *username, json_t *value, const struct _u_request *request);
json_t *auth_check_identify_scheme(struct config_elements *config, const char *scheme_type, const char *scheme_name, json_t *value, const struct _u_request *request);
void json_decref(json_t *json);