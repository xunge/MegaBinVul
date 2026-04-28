#include <setjmp.h>
#include <string>

using String = std::string;

struct JpegInput {
    JpegInput(String const& filename);
    JpegInput(String const& filename, jmp_buf& buf);
};

jmp_buf setjmp_buffer;

#define DIP__DECLARE_JPEG_EXIT(msg)