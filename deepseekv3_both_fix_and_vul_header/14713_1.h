#include <algorithm>
#include <string>
#include <vector>

class GURL {
 public:
  const std::string& spec() const;
};

class DataURL {
 public:
  static bool Parse(const GURL& url, std::string* mime_type,
                   std::string* charset, std::string* data);
};

namespace base {
template <typename CharT>
bool IsAsciiWhitespace(CharT c);

bool Base64Decode(const std::string& input, std::string* output);
void SplitString(const std::string& str, char delimiter, std::vector<std::string>* result);
void StringToLowerASCII(std::string* str);
}  // namespace base

namespace HttpUtil {
bool IsToken(const std::string& str);
}  // namespace HttpUtil

namespace UnescapeRule {
const int SPACES = 0;
const int URL_SPECIAL_CHARS = 0;
const int CONTROL_CHARS = 0;
const int SPOOFING_AND_CONTROL_CHARS = 0;
}  // namespace UnescapeRule

std::string UnescapeURLComponent(const std::string& url, int rules);

bool ParseMimeTypeWithoutParameter(const std::string& mime_type, void* unused1, void* unused2);

#define DCHECK(condition) ((void)0)
#define arraysize(array) (sizeof(array) / sizeof(array[0]))