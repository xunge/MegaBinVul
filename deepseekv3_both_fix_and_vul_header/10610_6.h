#include <vector>
#include <string>
#include <memory>
#include <cstdint>
#include <iostream>

namespace librevenge {
    class RVNGString {
    public:
        RVNGString();
        ~RVNGString();
        bool empty() const;
    };
    enum RVNG_SEEK_TYPE { RVNG_SEEK_SET };
}

namespace libstoff {
    class DebugFile {
    public:
        void addPos(long pos);
        void addNote(const char* note);
    };
    
    class DebugStream {
    public:
        std::string str() const;
        DebugStream& operator<<(const char* str);
        DebugStream& operator<<(int val);
        template<typename T> DebugStream& operator<<(const T& val);
    };
    
    void appendUnicode(uint32_t c, librevenge::RVNGString &str);
    librevenge::RVNGString getString(const std::vector<uint32_t> &text);
    void splitString(const librevenge::RVNGString &text, const librevenge::RVNGString &delim, librevenge::RVNGString &first, librevenge::RVNGString &second);
}

class STOFFInputStreamPtr {
public:
    long tell() const;
    void seek(long pos, librevenge::RVNG_SEEK_TYPE type);
    unsigned char peek() const;
    unsigned long readULong(int size);
    STOFFInputStreamPtr* operator->();
};

class StarZone {
public:
    STOFFInputStreamPtr input();
    libstoff::DebugFile& ascii();
    bool openSWRecord(char& type);
    bool readString(std::vector<uint32_t>& text);
    bool isCompatibleWith(int v1, int v2);
    bool isCompatibleWith(int v1, int v2, int v3);
    bool isCompatibleWith(int v1);
    long getRecordLastPosition();
    int getRecordLevel();
    void closeSWRecord(char type, const char* name);
};

struct STOFFVec2i {
    int x, y;
    STOFFVec2i(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

struct Data {
    librevenge::RVNGString m_name;
    STOFFVec2i m_selection;
    Data() : m_selection(0, 0) {}
};

class DatabaseName {
public:
    bool read(StarZone &zone);
    friend libstoff::DebugStream& operator<<(libstoff::DebugStream& out, const DatabaseName& db);
private:
    librevenge::RVNGString m_names[2];
    librevenge::RVNGString m_sql;
    std::vector<Data> m_dataList;
};

#define STOFF_DEBUG_MSG(x)