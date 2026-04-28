#include <signal.h>
#include <string>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

extern bool g_set_date;
extern void* g_shm;
extern void sig_handler(int sig);
extern void* get_shmTime(int shm_unit);
extern void put_shmTime(void** shm);
extern void time_ref_cb(void*);

namespace ros {
    void init(int argc, char** argv, const char* name);
    void spin();
    
    class TransportHints {
    public:
        TransportHints();
        TransportHints& unreliable();
        TransportHints& maxDatagramSize(int size);
        TransportHints& reliable();
        TransportHints& tcpNoDelay(bool no_delay);
    };
    
    class Subscriber {};
    
    class NodeHandle {
    public:
        NodeHandle(const std::string& ns);
        void param(const std::string& name, int& value, int default_value);
        void param(const std::string& name, bool& value, bool default_value);
        template<typename T> void param(const std::string& name, T& value, const T& default_value);
        Subscriber subscribe(const std::string& topic, int queue_size, void(*callback)(void*), const TransportHints& hints);
    };
    
    namespace names {
        std::string resolve(const std::string& name, bool remap);
    }
}

#define ROS_INFO_STREAM(msg) std::cout << msg << std::endl