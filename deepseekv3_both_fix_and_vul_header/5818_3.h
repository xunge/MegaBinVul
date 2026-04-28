#include <string>
#include <cstddef>

enum TruncationKind {
    NoTruncation,
    SrcLikeAttributeTruncation,
    ScriptLikeAttributeTruncation
};

class String {
public:
    String();
    String(const char*);
    size_t length() const;
    void truncate(size_t);
    String removeCharacters(bool (*)(char));
    char operator[](size_t) const;
};

class XSSAuditor {
public:
    std::string m_encoding;
    String fullyDecodeString(const String&, const std::string&);
    void truncateForSrcLikeAttribute(String&);
    void truncateForScriptLikeAttribute(String&);
    String canonicalize(String snippet, TruncationKind treatment);
};

bool isHTMLSpace(char);
bool isNonCanonicalCharacter(char);

const size_t kMaximumFragmentLengthTarget = 1024;