#include <string>

namespace crow {
    struct request {
        // Placeholder for crow::request
    };
}

crow::request req;
std::string header_field;
std::string header_value;
int header_building_state;
int qs_point;
bool message_complete;
int state;

#define CROW_NEW_MESSAGE() 0