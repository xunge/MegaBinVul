#include <string>
#include <cstring>

#define MAX_SIP_URI_LEN 256

struct su_home_t {
    su_home_t* getHome();
};

struct url_t {
    const char* url_host;
    const char* url_port;
};

typedef struct msg_param_t msg_param_t;

extern su_home_t* theOneAndOnlyController;

int sip_name_addr_d(su_home_t*, char**, char const**, url_t*, msg_param_t const**, char const**);
int sip_name_addr_e(char*, int, int, char const*, int, url_t*, msg_param_t const*, char const*);
void su_free(su_home_t*, void*);