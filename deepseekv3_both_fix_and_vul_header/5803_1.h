class WebContentsImpl {
public:
    void CancelModalDialogsForRenderManager();
};

class DialogManager {
public:
    void ResetDialogState(WebContentsImpl*);
};

extern DialogManager* dialog_manager_;