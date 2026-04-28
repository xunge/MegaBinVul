#include <string.h>

class DCTStream {
private:
    unsigned char *current;
    unsigned char *limit;
    bool readLine();
public:
    int getChars(int nChars, unsigned char *buffer);
};