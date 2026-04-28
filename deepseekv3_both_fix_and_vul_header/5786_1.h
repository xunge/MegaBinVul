#include <string>
#include <cassert>

namespace content {
class DownloadItem {
 public:
  enum DownloadState {
    IN_PROGRESS,
  };
  bool CanShowInFolder() const;
  bool CanOpenDownload() const;
  bool IsDone() const;
  bool IsPaused() const;
  DownloadState GetState() const;
  bool CanResume() const;
  std::string GetTargetFilePath() const;
};
}  // namespace content

namespace download_crx_util {
bool IsExtensionDownload(const content::DownloadItem& item);
}  // namespace download_crx_util

namespace download_util {
bool IsAllowedToOpenAutomatically(const std::string& file_path);
}  // namespace download_util

class DownloadCommands {
 public:
  enum Command {
    SHOW_IN_FOLDER,
    OPEN_WHEN_COMPLETE,
    PLATFORM_OPEN,
    ALWAYS_OPEN_TYPE,
    CANCEL,
    PAUSE,
    RESUME,
    DISCARD,
    KEEP,
    LEARN_MORE_SCANNING,
    LEARN_MORE_INTERRUPTED
  };
  bool IsCommandEnabled(Command command) const;

 private:
  content::DownloadItem* download_item_;
};

#define NOTREACHED() assert(false)