#include <algorithm>
#include <cstdint>

struct mavlink_message_t;

class MavlinkReceiver {
public:
    void handle_message_trajectory_representation_waypoints(mavlink_message_t *msg);
};

struct vehicle_trajectory_waypoint_s {
    static const int NUMBER_POINTS = 5;
    struct {
        float position[3];
        float velocity[3];
        float acceleration[3];
        float yaw;
        float yaw_speed;
        bool point_valid;
        uint8_t type;
    } waypoints[NUMBER_POINTS];
    uint64_t timestamp;
};

struct mavlink_trajectory_representation_waypoints_t {
    uint64_t time_usec;
    uint8_t valid_points;
    float pos_x[5];
    float pos_y[5];
    float pos_z[5];
    float vel_x[5];
    float vel_y[5];
    float vel_z[5];
    float acc_x[5];
    float acc_y[5];
    float acc_z[5];
    float pos_yaw[5];
    float vel_yaw[5];
    uint8_t command[5];
};

void mavlink_msg_trajectory_representation_waypoints_decode(const mavlink_message_t* msg, mavlink_trajectory_representation_waypoints_t* trajectory);

namespace math {
    template<typename T, typename U>
    auto min(T a, U b) -> decltype(a < b ? a : b) { return a < b ? a : b; }
}

uint64_t hrt_absolute_time();

class Publisher {
public:
    void publish(const vehicle_trajectory_waypoint_s&);
};

extern Publisher _trajectory_waypoint_pub;