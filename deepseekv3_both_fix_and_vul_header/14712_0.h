#include <string>

enum FileSystemType {
  kFileSystemTypeUnknown,
  kFileSystemTypePersistent,
  kFileSystemTypeTemporary,
  kFileSystemTypeIsolated,
  kFileSystemTypeExternal,
  kFileSystemTypeTest
};

const char kPersistentDir[] = "persistent";
const char kTemporaryDir[] = "temporary";
const char kIsolatedDir[] = "isolated";
const char kExternalDir[] = "external";
const char kTestDir[] = "test";

class GURL {
public:
  bool is_valid() const;
  bool SchemeIsFileSystem() const;
  const GURL* inner_url() const;
  std::string path() const;
  GURL GetOrigin() const;
};

namespace net {
  enum UnescapeRule {
    SPACES,
    URL_SPECIAL_CHARS,
    SPOOFING_AND_CONTROL_CHARS,
    CONTROL_CHARS
  };
  std::string UnescapeURLComponent(const std::string& url, int rules);
}

namespace base {
  class FilePath {
  public:
    static FilePath FromUTF8Unsafe(const std::string& path);
    bool ReferencesParent() const;
    FilePath NormalizePathSeparators() const;
    FilePath StripTrailingSeparators() const;
  };
}

#define DCHECK(condition) ((void)0)
#define arraysize(array) (sizeof(array)/sizeof(array[0]))