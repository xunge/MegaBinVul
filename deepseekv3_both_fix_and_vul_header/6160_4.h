#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

#define EXV_WARNING std::cerr

namespace Exiv2 {
    struct Rational {
        int first;
        int second;
    };

    enum TypeId {
        asciiString
    };

    class Value {
    public:
        bool ok() const;
    };

    class Exifdatum {
    public:
        std::string toString() const;
        Value& value() const;
        int count() const;
        float toFloat(int n) const;
        Rational toRational(int n) const;
        long typeId() const;
    };

    class ExifKey {
    public:
        ExifKey(const char* key);
    };

    class ExifData {
    public:
        typedef std::vector<Exifdatum>::iterator iterator;
        iterator findKey(const ExifKey& key);
        iterator end();
        void erase(iterator pos);
    };

    template<typename T>
    T stringTo(const std::string& s, bool& ok);
}

class Converter {
private:
    Exiv2::ExifData* exifData_;
    std::map<std::string, std::string>* xmpData_;
    bool erase_;
    bool prepareXmpTarget(const char* to);
public:
    void cnvExifDate(const char* from, const char* to);
};

using Exiv2::Rational;
using Exiv2::ExifData;
using Exiv2::ExifKey;
using Exiv2::stringTo;
using Exiv2::asciiString;