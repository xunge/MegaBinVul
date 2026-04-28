#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

class Exiv2 {
public:
    class ExifKey {
    public:
        ExifKey(const std::string& key);
        friend std::ostream& operator<<(std::ostream& os, const ExifKey& ek);
    };
    
    class ExifData {
    public:
        class iterator {
        public:
            std::string toString();
            void setValue(const std::string& value);
            bool operator==(const iterator& other) const;
            iterator* operator->();
        };
        
        iterator findKey(const ExifKey& key);
        iterator end();
    };
};

class Params {
public:
    static Params& instance();
    bool verbose_;
};

class Adjust {
public:
    int adjustDateTime(Exiv2::ExifData& exifData, const std::string& key, const std::string& path) const;
    int str2Tm(const std::string& timeStr, struct tm* tm) const;
    std::string time2Str(time_t time) const;
    int yearAdjustment_;
    int monthAdjustment_;
    int dayAdjustment_;
    long adjustment_;
};

const char* _(const char* msg);

std::ostream& operator<<(std::ostream& os, const Exiv2::ExifKey& ek);