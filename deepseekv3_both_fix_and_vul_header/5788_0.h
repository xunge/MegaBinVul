#include <string>
#include <unordered_set>

namespace base {
class FilePath {
 public:
  typedef std::wstring StringType;
  static const wchar_t kExtensionSeparator;
  StringType Extension() const { return StringType(); }
};
const wchar_t FilePath::kExtensionSeparator = L'.';
}  // namespace base

class DownloadPrefs {
 public:
  bool IsAutoOpenEnabledBasedOnExtension(const base::FilePath& path) const;
  bool ShouldOpenPdfInSystemReader() const { return false; }

 private:
  std::unordered_set<base::FilePath::StringType> auto_open_;
};

#define FILE_PATH_LITERAL(x) L##x
#define OS_WIN 1
#define OS_LINUX 0
#define OS_MACOSX 0
#define OS_IOS 0
#define DCHECK(condition) ((void)0)