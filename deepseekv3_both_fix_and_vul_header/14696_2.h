#include <string>
#include <cstddef>

#define MagickPPExport

enum ExceptionType {
    UndefinedException,
    BlobError,
    BlobFatalError,
    BlobWarning,
    CacheError,
    CacheFatalError,
    CacheWarning,
    CoderError,
    CoderFatalError,
    CoderWarning,
    ConfigureError,
    ConfigureFatalError,
    ConfigureWarning,
    CorruptImageError,
    CorruptImageFatalError,
    CorruptImageWarning,
    DelegateError,
    DelegateFatalError,
    DelegateWarning,
    DrawError,
    DrawFatalError,
    DrawWarning,
    FileOpenError,
    FileOpenFatalError,
    FileOpenWarning,
    ImageError,
    ImageFatalError,
    ImageWarning,
    MissingDelegateError,
    MissingDelegateFatalError,
    MissingDelegateWarning,
    ModuleError,
    ModuleFatalError,
    ModuleWarning,
    MonitorError,
    MonitorFatalError,
    MonitorWarning,
    OptionError,
    OptionFatalError,
    OptionWarning,
    PolicyWarning,
    PolicyError,
    PolicyFatalError,
    RegistryError,
    RegistryFatalError,
    RegistryWarning,
    ResourceLimitError,
    ResourceLimitFatalError,
    ResourceLimitWarning,
    StreamError,
    StreamFatalError,
    StreamWarning,
    TypeError,
    TypeFatalError,
    TypeWarning,
    XServerError,
    XServerFatalError,
    XServerWarning,
    ErrorException
};

struct ExceptionInfo {
    ExceptionType severity;
    const char *reason;
    const char *description;
    void *exceptions;
    void *semaphore;
};

struct Exception {
    void nested(Exception *);
};

struct LinkedListInfo {};

struct ErrorBlob {
    ErrorBlob(std::string, Exception*);
};
struct WarningBlob {
    WarningBlob(std::string, Exception*);
};
struct ErrorCache {
    ErrorCache(std::string, Exception*);
};
struct WarningCache {
    WarningCache(std::string, Exception*);
};
struct ErrorCoder {
    ErrorCoder(std::string, Exception*);
};
struct WarningCoder {
    WarningCoder(std::string, Exception*);
};
struct ErrorConfigure {
    ErrorConfigure(std::string, Exception*);
};
struct WarningConfigure {
    WarningConfigure(std::string, Exception*);
};
struct ErrorCorruptImage {
    ErrorCorruptImage(std::string, Exception*);
};
struct WarningCorruptImage {
    WarningCorruptImage(std::string, Exception*);
};
struct ErrorDelegate {
    ErrorDelegate(std::string, Exception*);
};
struct WarningDelegate {
    WarningDelegate(std::string, Exception*);
};
struct ErrorDraw {
    ErrorDraw(std::string, Exception*);
};
struct WarningDraw {
    WarningDraw(std::string, Exception*);
};
struct ErrorFileOpen {
    ErrorFileOpen(std::string, Exception*);
};
struct WarningFileOpen {
    WarningFileOpen(std::string, Exception*);
};
struct ErrorImage {
    ErrorImage(std::string, Exception*);
};
struct WarningImage {
    WarningImage(std::string, Exception*);
};
struct ErrorMissingDelegate {
    ErrorMissingDelegate(std::string, Exception*);
};
struct WarningMissingDelegate {
    WarningMissingDelegate(std::string, Exception*);
};
struct ErrorModule {
    ErrorModule(std::string, Exception*);
};
struct WarningModule {
    WarningModule(std::string, Exception*);
};
struct ErrorMonitor {
    ErrorMonitor(std::string, Exception*);
};
struct WarningMonitor {
    WarningMonitor(std::string, Exception*);
};
struct ErrorOption {
    ErrorOption(std::string, Exception*);
};
struct WarningOption {
    WarningOption(std::string, Exception*);
};
struct ErrorPolicy {
    ErrorPolicy(std::string, Exception*);
};
struct WarningPolicy {
    WarningPolicy(std::string, Exception*);
};
struct ErrorRegistry {
    ErrorRegistry(std::string, Exception*);
};
struct WarningRegistry {
    WarningRegistry(std::string, Exception*);
};
struct ErrorResourceLimit {
    ErrorResourceLimit(std::string, Exception*);
};
struct WarningResourceLimit {
    WarningResourceLimit(std::string, Exception*);
};
struct ErrorStream {
    ErrorStream(std::string, Exception*);
};
struct WarningStream {
    WarningStream(std::string, Exception*);
};
struct ErrorType {
    ErrorType(std::string, Exception*);
};
struct WarningType {
    WarningType(std::string, Exception*);
};
struct ErrorUndefined {
    ErrorUndefined(std::string, Exception*);
};
struct ErrorXServer {
    ErrorXServer(std::string, Exception*);
};
struct WarningXServer {
    WarningXServer(std::string, Exception*);
};

namespace MagickCore {
    const ExceptionType ErrorException = ErrorException;
}

namespace Magick {
    std::string formatExceptionMessage(const ExceptionInfo *);
    Exception* createException(const ExceptionInfo *);
    void LockSemaphoreInfo(void*);
    void UnlockSemaphoreInfo(void*);
    void DestroyExceptionInfo(ExceptionInfo*);
    size_t GetNumberOfElementsInLinkedList(LinkedListInfo*);
    void* GetValueFromLinkedList(LinkedListInfo*, size_t);
    int LocaleCompare(const char*, const char*);
    void throwException(ExceptionInfo*, bool);
}