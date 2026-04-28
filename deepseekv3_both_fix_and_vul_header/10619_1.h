#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef enum {
    HSM_COM_OK,
    HSM_COM_ERROR,
    HSM_COM_PATH_ERR,
    HSM_COM_BIND_ERR,
    HSM_COM_CHMOD_ERR,
    HSM_COM_CONX_ERR,
    HSM_COM_SEND_ERR
} hsm_com_errno_t;

typedef enum {
    HSM_COM_C_STATE_IN,
    HSM_COM_C_STATE_CT
} hsm_com_client_state_t;

typedef struct {
    char c_path[108];  // Assuming UNIX domain socket path max length
    char s_path[108];
    int client_fd;
    hsm_com_client_state_t client_state;
} hsm_com_client_hdl_t;

hsm_com_errno_t unix_sck_send_conn(hsm_com_client_hdl_t *hdl, int arg);