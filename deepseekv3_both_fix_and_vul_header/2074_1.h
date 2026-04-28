#include <string>

#define M_GET 0
#define M_POST 1

using std::string;

struct request_rec {
    int method_number;
    const char* args;
};

typedef void* params_t;

void debug(const string& msg);
params_t parse_query_string(const string& query);
bool get_post_data(request_rec* r, string& query);
void merge_params(params_t& src, params_t& dst);