#include <stddef.h>
#include <stdint.h>

typedef uint8_t byte;
typedef uint16_t word16;

typedef enum {
    MQTT_PACKET_TYPE_RESERVED,
    MQTT_PACKET_TYPE_PUBLISH,
    MQTT_PACKET_TYPE_ANY
} MqttPacketType;

typedef enum {
    MQTT_MSG_BEGIN,
    MQTT_MSG_WAIT,
    MQTT_MSG_READ,
    MQTT_MSG_READ_PAYLOAD,
    MQTT_MSG_WRITE,
    MQTT_MSG_WRITE_PAYLOAD,
    MQTT_MSG_AUTH
} MqttMsgState;

typedef enum {
    MQTT_PK_BEGIN
} MqttPacketState;

typedef enum {
    MQTT_CODE_SUCCESS,
    MQTT_CODE_ERROR_BAD_ARG,
    MQTT_CODE_ERROR_STAT,
    MQTT_CODE_CONTINUE
} MqttReturnCode;

typedef int MqttMsgStat;  // Simplified to just an integer type

typedef struct MqttClient {
    byte* rx_buf;
    word16 rx_buf_len;
    struct {
        MqttPacketState stat;
        word16 buf_len;
    } packet;
    MqttMsgStat msg;
#ifdef WOLFMQTT_MULTITHREAD
    int lockRecv;
    int lockClient;
#endif
} MqttClient;

typedef struct MqttPendResp {
    int packetDone;
    int packet_ret;
    void* packet_obj;
    MqttPacketType packet_type;
    int packetProcessing;
} MqttPendResp;

#ifdef WOLFMQTT_MULTITHREAD
int wm_SemLock(int*);
int wm_SemUnlock(int*);
#endif

int MqttPacket_Read(MqttClient*, byte*, word16, int);
int MqttClient_DecodePacket(MqttClient*, byte*, word16, void*, MqttPacketType*, void*, word16*);
int MqttClient_HandlePacket(MqttClient*, MqttPacketType, void*, int);
int MqttIsPubRespPacket(MqttPacketType);
const char* MqttPacket_TypeDesc(MqttPacketType);
const char* MqttClient_ReturnCodeToString(int);

#define PRINTF(...)
#define FALL_THROUGH