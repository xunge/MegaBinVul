#include <cstdint>
#include <chrono>

uint32_t maxControlMsgsPerInterval_;
uint32_t maxDirectErrorHandlingPerInterval_;
uint32_t maxHeadersPerInterval_;
std::chrono::milliseconds controlMsgIntervalDuration_;
std::chrono::milliseconds directErrorHandlingIntervalDuration_;
std::chrono::milliseconds headersIntervalDuration_;