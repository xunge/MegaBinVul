#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/select.h>

struct global_struct {
    int do_exit;
    float gps_loc[5];
    int record_data;
    FILE *f_gps;
    int save_gps;
    int gc_pipe[2];
};
extern struct global_struct G;