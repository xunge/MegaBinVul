#include <stdio.h>
#include <stdlib.h>

typedef struct _SmsConn *SmsConn;

typedef void (*SmsCallbackFunc)(void);

typedef struct {
    SmsCallbackFunc callback;
    void *manager_data;
} SmsCallback;

typedef struct {
    SmsCallback register_client;
    SmsCallback interact_request;
    SmsCallback interact_done;
    SmsCallback save_yourself_request;
    SmsCallback save_yourself_phase2_request;
    SmsCallback save_yourself_done;
    SmsCallback close_connection;
    SmsCallback set_properties;
    SmsCallback delete_properties;
    SmsCallback get_properties;
} SmsCallbacks;

typedef struct {
    SmsConn conn;
    unsigned int protocol_timeout;
    char *description;
} GsmXSMPClientPrivate;

typedef struct _GsmXSMPClient {
    GsmXSMPClientPrivate *priv;
} GsmXSMPClient;

#define SmsRegisterClientProcMask (1L << 0)
#define SmsInteractRequestProcMask (1L << 1)
#define SmsInteractDoneProcMask (1L << 2)
#define SmsSaveYourselfRequestProcMask (1L << 3)
#define SmsSaveYourselfP2RequestProcMask (1L << 4)
#define SmsSaveYourselfDoneProcMask (1L << 5)
#define SmsCloseConnectionProcMask (1L << 6)
#define SmsSetPropertiesProcMask (1L << 7)
#define SmsDeletePropertiesProcMask (1L << 8)
#define SmsGetPropertiesProcMask (1L << 9)

void register_client_callback(void);
void interact_request_callback(void);
void interact_done_callback(void);
void save_yourself_request_callback(void);
void save_yourself_phase2_request_callback(void);
void save_yourself_done_callback(void);
void close_connection_callback(void);
void set_properties_callback(void);
void delete_properties_callback(void);
void get_properties_callback(void);