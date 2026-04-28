#include <map>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>

typedef long long qpdf_offset_t;

class QPDFExc {
public:
    QPDFExc(int, std::string, std::string, int, std::string);
};

class QTC {
public:
    static void TC(const char*, const char*, int);
    static void TC(const char*, const char*);
};

class QUtil {
public:
    static bool is_space(char);
    static std::string int_to_string(int);
};

enum qpdf_error_code_e {
    qpdf_e_damaged_pdf
};

struct ObjGen {
    int getObj() const;
};

class QPDF {
public:
    struct Member {
        struct File {
            void seek(qpdf_offset_t, int);
            void read(char*, size_t);
            std::string getName();
        }* file;
        struct Trailer {
            bool isInitialized();
            struct Object {
                int getIntValue();
            };
            Object getKey(const char*);
        } trailer;
        std::map<ObjGen, std::pair<int, int>> xref_table;
        std::set<int> deleted_objects;
    }* m;

    void read_xref(qpdf_offset_t);
    qpdf_offset_t read_xrefTable(qpdf_offset_t);
    qpdf_offset_t read_xrefStream(qpdf_offset_t);
    void warn(const QPDFExc&);
};