#include <map>
#include <string>
#include <vector>

namespace base {
class DictionaryValue {
public:
    bool GetBoolean(const std::string& path, bool* out_value) const;
};
}

enum PreviewEventType {
  PREVIEW_EVENT_REQUESTED,
  PREVIEW_EVENT_MAX
};

enum PrintPreviewError {
  PREVIEW_ERROR_BAD_SETTING,
  FAIL_PREVIEW
};

struct PrintMsg_Print_Params {
  int document_cookie;
  bool is_first_request;
  bool supports_alpha_blend;
};

struct PrintHostMsg_SetOptionsFromDocument_Params {};

struct PrintHostMsg_PrintPreviewInvalidPrinterSettings {
  PrintHostMsg_PrintPreviewInvalidPrinterSettings(int routing_id, int cookie);
};

struct PrintHostMsg_SetOptionsFromDocument {
  PrintHostMsg_SetOptionsFromDocument(int routing_id, 
                                     const PrintHostMsg_SetOptionsFromDocument_Params& options);
};

struct PrintPagesParams {
  PrintMsg_Print_Params params;
};

class PrintPreviewContext {
public:
  void OnPrintPreview();
  bool IsModifiable();
  void set_generate_draft_pages(bool generate);
  bool source_frame();
  bool source_node();
  PrintPreviewError last_error();
};

class UMA_HISTOGRAM_ENUMERATION {
public:
  UMA_HISTOGRAM_ENUMERATION(const char* name, PreviewEventType event, PreviewEventType max);
};

#define NOTREACHED() ((void)0)
#define CHECK_LE(a, b) ((void)0)

class PrintWebViewHelper {
public:
  void OnPrintPreview(const base::DictionaryValue& settings);
protected:
  int routing_id();
  void Send(void* msg);
  bool UpdatePrintSettings(bool frame, bool node, const base::DictionaryValue& settings);
  void DidFinishPrinting(PrintPreviewError error);
  bool SetOptionsFromPdfDocument(PrintHostMsg_SetOptionsFromDocument_Params* options);
  void PrepareFrameForPreviewDocument();

  int ipc_nesting_level_;
  PrintPreviewContext print_preview_context_;
  PrintPagesParams* print_pages_params_;
  bool notify_browser_of_print_failure_;
  bool is_print_ready_metafile_sent_;
};

const char kSettingGenerateDraftData[] = "generateDraftData";