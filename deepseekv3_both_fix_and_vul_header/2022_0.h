#include <vector>
#include <cstddef>

#define PARAM_MAX 100

class Dispatcher {
private:
    bool parsed;
    std::vector<int> parsed_params;
    void parse_params();
public:
    int getparam(size_t N, int defaultval);
};