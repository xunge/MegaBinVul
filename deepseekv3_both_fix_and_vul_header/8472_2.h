#include <string>
#include <cstddef>

using std::string;

class PacketReader {
public:
    string getLabel(unsigned int recurs);
private:
    string d_content;
    size_t d_pos;
    void getLabelFromContent(const string& content, size_t& pos, string& ret, unsigned int recurs);
    void getLabelFromContent(const string& content, size_t& pos, string& ret, unsigned int recurs, size_t& wirelength);
};