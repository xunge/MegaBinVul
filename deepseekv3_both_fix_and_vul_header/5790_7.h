#include <string>
#include <algorithm>

enum DownloadDangerLevel {
  NOT_DANGEROUS,
  DANGEROUS
};

namespace base {
class FilePath {
 public:
  typedef std::string StringType;
  static const char kExtensionSeparator = '.';
  StringType FinalExtension() const { return ""; }
};

bool IsStringASCII(const std::string& str) { return true; }
std::string UTF16ToASCII(const std::wstring& str) { return ""; }
bool LowerCaseEqualsASCII(const std::string& a, const char* b) { return false; }
}

struct ExecutableInfo {
  const char* extension;
  DownloadDangerLevel level;
};

const ExecutableInfo g_executables[] = {
    {"exe", DANGEROUS},
    {"bat", DANGEROUS},
    {"sh", DANGEROUS}
};

template <typename T, size_t N>
constexpr size_t arraysize(T (&)[N]) { return N; }

struct FileType {
  DownloadDangerLevel danger_level;
};

FileType GetFileType(const base::FilePath& path) { return {NOT_DANGEROUS}; }

#if !defined(OS_WIN) && !defined(OS_POSIX)
#define OS_POSIX 1
#endif