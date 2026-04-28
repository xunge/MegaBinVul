#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdio>

class String {
public:
    String() {}
    String(int size, int) {}
    String(int size, const char*) {}
    char* mutableData() { return nullptr; }
    void setSize(int) {}
    bool empty() const { return false; }
    const char* data() const { return nullptr; }
    size_t size() const { return 0; }
    operator bool() const { return !empty(); }
};

String empty_string() { return String(); }

double php_math_round(double d, int dec) { return round(d * pow(10, dec)) / pow(10, dec); }

void raise_error(const char*) {}

enum { ReserveString = 0 };