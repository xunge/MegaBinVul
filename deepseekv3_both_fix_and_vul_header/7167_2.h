#include <iostream>
#include <fstream>
#include <memory>

class LibRaw_file_datastream {
private:
    std::unique_ptr<std::filebuf> f;
public:
    char* gets(char* str, int sz);
};

#define LR_STREAM_CHK()