#include <cstdint>
#include <vector>

namespace blink {
enum class WebFileError;
}

namespace FileError {
enum ErrorCode {
    OK,
    ABORT_ERR
};
}

class FileWriter {
public:
    enum OperationType {
        OperationNone,
        OperationAbort
    };
    enum ReadyState {
        WRITING
    };

    void didFail(blink::WebFileError code);
    void completeAbort();
    void signalCompletion(FileError::ErrorCode);
    void unsetPendingActivity(FileWriter*);

    OperationType m_operationInProgress;
    OperationType m_queuedOperation;
    ReadyState m_readyState;
    std::vector<uint8_t> m_blobBeingWritten;
};

#define ASSERT(expr) (void)0