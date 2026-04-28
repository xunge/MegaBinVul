#include <set>
#include <string>
#include <cassert>

#define DCHECK assert

namespace base {
class FilePath {
 public:
  typedef std::wstring StringType;
  static const wchar_t kExtensionSeparator;
  StringType Extension() const;
};
}  // namespace base

namespace download_util {
bool IsAllowedToOpenAutomatically(const base::FilePath& file_name);
}  // namespace download_util

class DownloadPrefs {
 public:
  bool EnableAutoOpenBasedOnExtension(const base::FilePath& file_name);
 private:
  std::set<base::FilePath::StringType> auto_open_;
  void SaveAutoOpenState();
};