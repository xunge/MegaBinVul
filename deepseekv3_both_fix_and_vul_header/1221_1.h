#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

struct PortForwardSourceRequest {
    struct Source {
        void set_name(const string&);
        void set_port(int);
    };
    struct Destination {
        void set_name(const string&);
        void set_port(int);
    };
    
    void set_environmentvariable(const string&);
    Source* mutable_source();
    Destination* mutable_destination();
};

vector<string> split(const string&, char);
extern ostream& STFATAL;