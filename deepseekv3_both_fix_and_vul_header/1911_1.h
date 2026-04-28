#include <setjmp.h>
#include <string>

using String = std::string;

struct FileInformation {};
struct JpegInput {
    JpegInput(String const&) {}
    JpegInput(String const&, jmp_buf&) {}
};

FileInformation GetJPEGInfo(JpegInput const&);

jmp_buf setjmp_buffer;

#define DIP__DECLARE_JPEG_EXIT(msg)