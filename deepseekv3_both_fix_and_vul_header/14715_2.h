#include <string>

namespace base {
class StringPiece {
public:
    std::string as_string() const;
    bool empty() const;
};
}

namespace net {
enum UnescapeRule {
    URL_SPECIAL_CHARS,
    SPOOFING_AND_CONTROL_CHARS,
    CONTROL_CHARS
};

std::string UnescapeURLComponent(const std::string&, int);
}

namespace RE2 {
bool Consume(std::string*, const std::string&);
}

class Result {
public:
    void set_name(const std::string&);
    void set_value(const base::StringPiece&);
};

class FormDataParserMultipart {
public:
    bool GetNextNameValue(Result* result);
private:
    enum State {
        STATE_READY,
        STATE_ERROR,
        STATE_SUSPEND
    };
    State state_;
    std::string source_;
    std::string crlf_pattern();
    bool TryReadHeader(base::StringPiece*, base::StringPiece*, bool*);
    bool FinishReadingPart(base::StringPiece*);
};