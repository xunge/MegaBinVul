#include <stdint.h>
#include <stddef.h>

typedef enum {
    picoquic_packet_context_initial,
    picoquic_packet_context_handshake,
    picoquic_packet_context_application
} picoquic_packet_context_enum;

typedef enum {
    picoquic_congestion_notification_acknowledgement
} picoquic_congestion_notification_enum;

typedef struct picoquic_path_t picoquic_path_t;
typedef struct picoquic_cnx_t picoquic_cnx_t;
typedef struct picoquic_packet_t picoquic_packet_t;

struct picoquic_packet_t {
    picoquic_packet_t* next_packet;
    picoquic_packet_t* previous_packet;
    picoquic_path_t* send_path;
    uint32_t length;
    int is_congestion_controlled;
};

struct picoquic_path_t {
    struct {
        picoquic_packet_t* retransmit_oldest;
    } pkt_ctx[3];
    uint64_t smoothed_rtt;
    uint64_t rtt_variant;
};

struct picoquic_cnx_t {
    void* congestion_alg;
};

#define PICOQUIC_INITIAL_RTT 0

void picoquic_congestion_algorithm_notify_func(picoquic_cnx_t* cnx, picoquic_path_t* path,
    picoquic_congestion_notification_enum notification, uint64_t rtt_measurement,
    uint64_t nb_bytes_acknowledged, uint64_t lost_packet_number, uint64_t current_time);

int picoquic_dequeue_retransmit_packet(picoquic_cnx_t* cnx, picoquic_packet_t* packet, int is_retransmit_needed);