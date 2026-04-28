#include <stdbool.h>

#define NET_MAXPLAYERS 4

typedef bool boolean;

typedef struct net_packet_s net_packet_t;

typedef struct {
    int ticdup;
    int extratics;
    int deathmatch;
    int nomonsters;
    int fast_monsters;
    int respawn_monsters;
    int episode;
    int map;
    signed int skill;
    int gameversion;
    int lowres_turn;
    int new_sync;
    unsigned int timelimit;
    signed int loadgame;
    int random;
    int num_players;
    signed int consoleplayer;
    int player_classes[NET_MAXPLAYERS];
} net_gamesettings_t;

boolean NET_ReadInt8(net_packet_t *packet, unsigned int *value);
boolean NET_ReadSInt8(net_packet_t *packet, signed int *value);
boolean NET_ReadInt32(net_packet_t *packet, unsigned int *value);