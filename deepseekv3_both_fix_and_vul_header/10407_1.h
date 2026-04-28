#include <stdbool.h>
#include <assert.h>

typedef unsigned char u_char;

#define PSEUDO_APP_LAYER_INDEX 0
#define PSEUDO_LINK_LAYER_LEN 0
#define PSEUDO_LENGTH_INDEX 0
#define PSEUDO_CONTROL_FIELD_INDEX 0
#define PSEUDO_TRANSPORT_INDEX 0

struct Endpoint {
    bool in_hdr;
    u_char* buffer;
    int buffer_len;
    u_char pkt_length;
    u_char tpflags;
    int pkt_cnt;
};

class Analyzer {
public:
    void Weird(const char*);
    void ProtocolViolation(const char*);
    void ProtocolConfirmation();
};

class Interpreter {
public:
    void NewData(bool, u_char*, u_char*);
};

class DNP3_Base {
protected:
    Endpoint orig_state;
    Endpoint resp_state;
    Analyzer* analyzer;
    Interpreter* interp;

    bool AddToBuffer(Endpoint*, int, const u_char**, int*);
    bool CheckCRC(int, u_char*, u_char*, const char*);
    void ClearEndpointState(bool);
    bool ParseAppLayer(Endpoint*);
public:
    bool ProcessData(int len, const u_char* data, bool orig);
};