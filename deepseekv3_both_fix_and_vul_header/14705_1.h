#include <cstddef>

namespace IPC {
class Message;
}  // namespace IPC

class PrintWebViewHelper {
public:
    int ipc_nesting_level_;
    bool OnMessageReceived(const IPC::Message& message);
    bool OnPrintPages(const IPC::Message& message);
    bool OnPrintForSystemDialog(const IPC::Message& message);
    bool OnInitiatePrintPreview(const IPC::Message& message);
    bool OnPrintPreview(const IPC::Message& message);
    bool OnPrintForPrintPreview(const IPC::Message& message);
    bool OnPrintingDone(const IPC::Message& message);
    bool SetScriptedPrintBlocked(const IPC::Message& message);
};

#define IPC_BEGIN_MESSAGE_MAP(class_name, message)
#define IPC_MESSAGE_HANDLER(message, function)
#define IPC_MESSAGE_UNHANDLED(handled)
#define IPC_END_MESSAGE_MAP()

#define PrintMsg_PrintPages 0
#define PrintMsg_PrintForSystemDialog 0
#define PrintMsg_InitiatePrintPreview 0
#define PrintMsg_PrintPreview 0
#define PrintMsg_PrintForPrintPreview 0
#define PrintMsg_PrintingDone 0
#define PrintMsg_SetScriptedPrintingBlocked 0

#define ENABLE_BASIC_PRINTING