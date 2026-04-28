#include <cstddef>

class PlayerGeneric
{
public:
    ~PlayerGeneric();

private:
    struct Mixer
    {
        bool isActive();
        bool isDeviceRemoved(void* device);
        void removeDevice(void* device);
    };

    Mixer* mixer;
    void* player;
    char* audioDriverName;
    void* listener;
};