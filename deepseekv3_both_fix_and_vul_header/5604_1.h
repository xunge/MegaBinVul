#include <stddef.h>
#include <stdbool.h>

class IPC {
public:
    class Message {};
};

class FrameMsg_Navigate {};
class FrameMsg_BeforeUnload {};
class FrameMsg_SwapOut {};
class FrameMsg_Stop {};
class FrameMsg_ContextMenuClosed {};
class FrameMsg_CustomContextMenuAction {};
class InputMsg_Undo {};
class InputMsg_Redo {};
class InputMsg_Cut {};
class InputMsg_Copy {};
class InputMsg_Paste {};
class InputMsg_PasteAndMatchStyle {};
class InputMsg_Delete {};
class InputMsg_SelectAll {};
class InputMsg_SelectRange {};
class InputMsg_Unselect {};
class InputMsg_MoveRangeSelectionExtent {};
class InputMsg_Replace {};
class InputMsg_ReplaceMisspelling {};
class InputMsg_ExtendSelectionAndDelete {};
class InputMsg_SetCompositionFromExistingText {};
class InputMsg_ExecuteNoValueEditCommand {};
class FrameMsg_CSSInsertRequest {};
class FrameMsg_JavaScriptExecuteRequest {};
class FrameMsg_JavaScriptExecuteRequestForTests {};
class FrameMsg_VisualStateRequest {};
class FrameMsg_SetEditableSelectionOffsets {};
class FrameMsg_SetupTransitionView {};
class FrameMsg_BeginExitTransition {};
class FrameMsg_RevertExitTransition {};
class FrameMsg_HideTransitionElements {};
class FrameMsg_ShowTransitionElements {};
class FrameMsg_Reload {};
class FrameMsg_TextSurroundingSelectionRequest {};
class FrameMsg_AddStyleSheetByURL {};
class FrameMsg_SetAccessibilityMode {};
class FrameMsg_DisownOpener {};
class FrameMsg_CommitNavigation {};
class FrameMsg_DidUpdateSandboxFlags {};
class FrameMsg_SelectPopupMenuItems {};
class FrameMsg_SelectPopupMenuItem {};
class InputMsg_CopyToFindPboard {};

class Document {
public:
    bool isNull() const;
    const char* url() const;
};

class Frame {
public:
    const Document& document() const;
};

class RenderFrameImpl {
public:
    bool OnMessageReceived(const IPC::Message& msg);
    void OnNavigate(const FrameMsg_Navigate&);
    void OnBeforeUnload(const FrameMsg_BeforeUnload&);
    void OnSwapOut(const FrameMsg_SwapOut&);
    void OnStop(const FrameMsg_Stop&);
    void OnContextMenuClosed(const FrameMsg_ContextMenuClosed&);
    void OnCustomContextMenuAction(const FrameMsg_CustomContextMenuAction&);
    void OnUndo(const InputMsg_Undo&);
    void OnRedo(const InputMsg_Redo&);
    void OnCut(const InputMsg_Cut&);
    void OnCopy(const InputMsg_Copy&);
    void OnPaste(const InputMsg_Paste&);
    void OnPasteAndMatchStyle(const InputMsg_PasteAndMatchStyle&);
    void OnDelete(const InputMsg_Delete&);
    void OnSelectAll(const InputMsg_SelectAll&);
    void OnSelectRange(const InputMsg_SelectRange&);
    void OnUnselect(const InputMsg_Unselect&);
    void OnMoveRangeSelectionExtent(const InputMsg_MoveRangeSelectionExtent&);
    void OnReplace(const InputMsg_Replace&);
    void OnReplaceMisspelling(const InputMsg_ReplaceMisspelling&);
    void OnExtendSelectionAndDelete(const InputMsg_ExtendSelectionAndDelete&);
    void OnSetCompositionFromExistingText(const InputMsg_SetCompositionFromExistingText&);
    void OnExecuteNoValueEditCommand(const InputMsg_ExecuteNoValueEditCommand&);
    void OnCSSInsertRequest(const FrameMsg_CSSInsertRequest&);
    void OnJavaScriptExecuteRequest(const FrameMsg_JavaScriptExecuteRequest&);
    void OnJavaScriptExecuteRequestForTests(const FrameMsg_JavaScriptExecuteRequestForTests&);
    void OnVisualStateRequest(const FrameMsg_VisualStateRequest&);
    void OnSetEditableSelectionOffsets(const FrameMsg_SetEditableSelectionOffsets&);
    void OnSetupTransitionView(const FrameMsg_SetupTransitionView&);
    void OnBeginExitTransition(const FrameMsg_BeginExitTransition&);
    void OnRevertExitTransition(const FrameMsg_RevertExitTransition&);
    void OnHideTransitionElements(const FrameMsg_HideTransitionElements&);
    void OnShowTransitionElements(const FrameMsg_ShowTransitionElements&);
    void OnReload(const FrameMsg_Reload&);
    void OnTextSurroundingSelectionRequest(const FrameMsg_TextSurroundingSelectionRequest&);
    void OnAddStyleSheetByURL(const FrameMsg_AddStyleSheetByURL&);
    void OnSetAccessibilityMode(const FrameMsg_SetAccessibilityMode&);
    void OnDisownOpener(const FrameMsg_DisownOpener&);
    void OnCommitNavigation(const FrameMsg_CommitNavigation&);
    void OnDidUpdateSandboxFlags(const FrameMsg_DidUpdateSandboxFlags&);
    void OnSelectPopupMenuItems(const FrameMsg_SelectPopupMenuItems&);
    void OnSelectPopupMenuItem(const FrameMsg_SelectPopupMenuItem&);
    void OnCopyToFindPboard(const InputMsg_CopyToFindPboard&);
};

class RenderFrameObserver {
public:
    virtual bool OnMessageReceived(const IPC::Message& msg) = 0;
};

template <typename T>
class ObserverListBase {
public:
    class Iterator {
    public:
        Iterator(ObserverListBase* list);
        T* GetNext();
    };
};

class ContentClient {
public:
    void SetActiveURL(const char* url);
};

ContentClient* GetContentClient();

#define IPC_BEGIN_MESSAGE_MAP(class_name, msg)
#define IPC_MESSAGE_HANDLER(message, function)
#define IPC_END_MESSAGE_MAP()

#if defined(OS_ANDROID) || defined(OS_MACOSX)
#define OS_ANDROID
#define OS_MACOSX
#endif

Frame* frame_;
ObserverListBase<RenderFrameObserver> observers_;