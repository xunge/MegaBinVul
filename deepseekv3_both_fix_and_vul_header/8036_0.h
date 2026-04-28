#include <stddef.h>

typedef void* (*PP_GetInterface_Func)(const char*);
typedef void (*PP_ConnectInstance_Func)(void*);

struct PPP_Flash_BrowserOperations_1_0 {};
struct PPP_Flash_BrowserOperations_1_2 {};
struct PPP_Flash_BrowserOperations_1_3 {};

const char* PPP_FLASH_BROWSEROPERATIONS_INTERFACE_1_0 = "";
const char* PPP_FLASH_BROWSEROPERATIONS_INTERFACE_1_2 = ""; 
const char* PPP_FLASH_BROWSEROPERATIONS_INTERFACE_1_3 = "";

namespace ppapi {
namespace proxy {
class BrokerSideDispatcher {
public:
    BrokerSideDispatcher(PP_ConnectInstance_Func connect_instance) {}
};
}  // namespace proxy
}  // namespace ppapi

class BrokerProcessDispatcher : public ppapi::proxy::BrokerSideDispatcher {
public:
    BrokerProcessDispatcher(PP_GetInterface_Func get_plugin_interface,
                          PP_ConnectInstance_Func connect_instance,
                          bool peer_is_browser);
    BrokerProcessDispatcher(PP_GetInterface_Func get_plugin_interface,
                          PP_ConnectInstance_Func connect_instance);
private:
    PP_GetInterface_Func get_plugin_interface_;
    const PPP_Flash_BrowserOperations_1_3* flash_browser_operations_1_3_;
    const PPP_Flash_BrowserOperations_1_2* flash_browser_operations_1_2_; 
    const PPP_Flash_BrowserOperations_1_0* flash_browser_operations_1_0_;
    bool peer_is_browser_;
};