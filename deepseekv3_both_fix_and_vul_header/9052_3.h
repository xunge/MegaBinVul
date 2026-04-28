#include <stdbool.h>
#include <string.h>
#include <vector>
#include <iostream>

#define LOG(severity) std::cerr
enum LogSeverity {
  WARNING
};

class base {
public:
    class PickleIterator {
    public:
        bool ReadInt(int*);
        bool ReadLength(int*);
        bool ReadFloat(float*);
        bool ReadData(const char**, int*);
    };
};

class WebCursorInfo {
public:
    enum Type {
        TypeCustom
    };
};

class Point {
public:
    void set_x(int x);
    void set_y(int y);
};

class Size {
public:
    void set_width(int w);
    void set_height(int h);
};

class WebCursor {
public:
    bool Deserialize(base::PickleIterator* iter);
private:
    int type_;
    float custom_scale_;
    std::vector<char> custom_data_;
    Point hotspot_;
    Size custom_size_;

    void ClampHotspot();
    bool DeserializePlatformData(base::PickleIterator* iter);
};

const int kMaxCursorDimension = 1024;