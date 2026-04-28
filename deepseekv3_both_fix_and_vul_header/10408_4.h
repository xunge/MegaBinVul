#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <algorithm>

#define PSEUDO_TRANSPORT_INDEX 0
#define PSEUDO_TRANSPORT_LEN 0

using u_char = unsigned char;
using std::min;

namespace binpac {
namespace DNP3 {
    class FlowBuffer {
    public:
        void BufferData(u_char* start, u_char* end);
        void FinishBuffer();
    };

    class DNP3_Flow {
    public:
        void FlowEOF();
        FlowBuffer* flow_buffer();
    };
}
}

struct Endpoint {
    u_char* buffer;
    int pkt_length;
    int buffer_len;
    int tpflags;
    bool encountered_first_chunk;
};

class DNP3_Interpreter {
public:
    binpac::DNP3::DNP3_Flow* upflow();
    binpac::DNP3::DNP3_Flow* downflow();
};

class Analyzer {
public:
    void Weird(const char* msg);
};

class Reporter {
public:
    void AnalyzerError(Analyzer* analyzer, const char* fmt, ...);
};

class DNP3_Base {
public:
    bool ParseAppLayer(Endpoint* endp);
};

extern Reporter* reporter;
extern Analyzer* analyzer;
extern Endpoint orig_state;
extern DNP3_Interpreter* interp;

bool CheckCRC(int n, u_char* data1, u_char* data2, const char* str);
void ClearEndpointState(bool orig);