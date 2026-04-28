#include <string>
#include <vector>
#include <map>

using string16 = std::u16string;

struct GURL {
  bool is_valid() const;
};

struct Pickle {
  const char* data();
  size_t size();
};

struct DropData {
  bool did_originate_from_renderer;
  struct NullableString16 {
    NullableString16(const string16&, bool);
  } text;
  GURL url;
  string16 url_title;
  NullableString16 html;
  GURL html_base_url;
  struct FileInfo {
    string16 path;
    string16 display_name;
    FileInfo(const string16& path, const string16& display_name);
  };
  std::vector<FileInfo> filenames;
  std::map<string16, string16> custom_data;
};

namespace ui {

class Clipboard {
public:
  struct FormatType {};
  static const FormatType& GetWebCustomDataFormatType();
};

struct OSExchangeData {
  bool DidOriginateFromRenderer() const;
  void GetString(string16* plain_text) const;
  enum FilenameConversionPolicy { DO_NOT_CONVERT_FILENAMES };
  void GetURLAndTitle(FilenameConversionPolicy, GURL* url, string16* url_title) const;
  void GetHtml(string16* html, GURL* html_base_url) const;
  struct FileInfo {
    struct FilePath {
      std::string AsUTF8Unsafe() const;
    };
    FilePath path;
    FilePath display_name;
  };
  bool GetFilenames(std::vector<FileInfo>* files) const;
  bool GetPickledData(const Clipboard::FormatType& format, Pickle* pickle) const;
};

void ReadCustomDataIntoMap(const char* data, size_t data_length, std::map<string16, string16>* map_data);

string16 UTF8ToUTF16(const std::string& utf8);

}  // namespace ui

namespace base {
using string16 = std::u16string;
using NullableString16 = DropData::NullableString16;
string16 UTF8ToUTF16(const std::string& utf8);
}  // namespace base