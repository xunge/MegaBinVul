#include <stdbool.h>

#define gr_face_dumbRendering 0x00000001

enum Tag {
    Silf
};

struct telemetry {
    struct category {
        category(int) {}
    };
    struct {
        int misc;
    } tele;
};

struct json {
    json& operator<<(const char*) { return *this; }
    json& operator<<(int) { return *this; }
    json& operator<<(json& (*)(json&)) { return *this; }
    static json& object(json& j) { return j; }
    static json& close(json& j) { return j; }
};

struct Face {
    struct Table {
        Table(Face&, Tag, unsigned int) {}
        operator bool() { return false; }
    };
    
    bool readGlyphs(unsigned int) { return false; }
    bool readFeatures() { return false; }
    bool readGraphite(Table&) { return false; }
    int error() { return 0; }
    const char* error_context() { return ""; }
    
    telemetry tele;
};

json* global_log = nullptr;