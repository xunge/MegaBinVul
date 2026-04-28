#include <cstdint>
#include <chrono>
#include <iostream>

constexpr uint32_t kMaxControlMsgsPerIntervalLowerBound = 0;
constexpr uint32_t kMaxDirectErrorHandlingPerIntervalLowerBound = 0;
constexpr uint32_t kMaxHeadersPerIntervalLowerBound = 0;

enum LogLevel {
    WARNING
};

#define XLOG_EVERY_MS(level, interval) std::cout

class HTTPSessionBase {
protected:
    class ControlMessageRateLimitFilter {
    public:
        void setParams(
            uint32_t maxControlMsgsPerInterval,
            uint32_t maxDirectErrorHandlingPerInterval,
            uint32_t maxHeadersPerInterval,
            std::chrono::milliseconds controlMsgIntervalDuration,
            std::chrono::milliseconds directErrorHandlingIntervalDuration,
            std::chrono::milliseconds headersIntervalDuration);
        
        void setParams(
            uint32_t maxControlMsgsPerInterval,
            uint32_t maxDirectErrorHandlingPerInterval,
            std::chrono::milliseconds controlMsgIntervalDuration,
            std::chrono::milliseconds directErrorHandlingIntervalDuration);
    };
    
    ControlMessageRateLimitFilter* controlMessageRateLimitFilter_;

    void setControlMessageRateLimitParams(
        uint32_t maxControlMsgsPerInterval,
        uint32_t maxDirectErrorHandlingPerInterval,
        uint32_t maxHeadersPerInterval,
        std::chrono::milliseconds controlMsgIntervalDuration,
        std::chrono::milliseconds directErrorHandlingIntervalDuration,
        std::chrono::milliseconds headersIntervalDuration);

    void setControlMessageRateLimitParams(
        uint32_t maxControlMsgsPerInterval,
        uint32_t maxDirectErrorHandlingPerInterval,
        std::chrono::milliseconds controlMsgIntervalDuration,
        std::chrono::milliseconds directErrorHandlingIntervalDuration);
};