#include <string>

namespace facebook::fb303 {
    enum ExportType {
        SUM,
        AVG
    };
}

class TLHTTPSessionStats {
private:
    struct Stat {
        Stat() = default;
        Stat(const std::string& name) {}
        Stat(const std::string& name, facebook::fb303::ExportType type) {}
        Stat(const std::string& name, int, int, int, facebook::fb303::ExportType, int, int, int) {}
        Stat(const std::string& name, int, int, int, facebook::fb303::ExportType, int, int, int, int) {}
    };

    Stat txnsOpen;
    Stat pendingBufferedReadBytes;
    Stat pendingBufferedWriteBytes;
    Stat txnsOpened;
    Stat txnsFromSessionReuse;
    Stat txnsTransactionStalled;
    Stat txnsSessionStalled;
    Stat egressContentLengthMismatches;
    Stat sessionPeriodicPingProbeTimeout;
    Stat presendIoSplit;
    Stat presendExceedLimit;
    Stat ttlbaTracked;
    Stat ttlbaReceived;
    Stat ttlbaTimeout;
    Stat ttlbaNotFound;
    Stat ttlbaExceedLimit;
    Stat ttbtxTracked;
    Stat ttbtxReceived;
    Stat ttbtxTimeout;
    Stat ttbtxNotFound;
    Stat ttbtxExceedLimit;
    Stat ctrlMsgsRateLimited;
    Stat headersRateLimited;
    Stat txnsPerSession;
    Stat sessionIdleTime;
    Stat ctrlMsgsInInterval;
    Stat headersInInterval;

public:
    TLHTTPSessionStats(const std::string& prefix);
};