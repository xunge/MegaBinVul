#include <string>

using String = std::string;

class Jpeg2KDecoder {
private:
    String m_signature;
    int m_stream;
    int m_image;
public:
    Jpeg2KDecoder();
};