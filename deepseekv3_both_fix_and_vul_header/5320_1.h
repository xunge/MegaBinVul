#include <stddef.h>

size_t Alignement_ExtraByte;
size_t Element_Size;
size_t Element_Offset;

#define DATA_BEGIN
#define DATA_END
#define LIST(x)
#define ATOM_BEGIN
#define ATOM_END
#define ATOM_END_DEFAULT
#define ATOM(x)
#define ATOM_DEFAULT(x)
#define ATOM_DEFAULT_ALONE(x)
#define ATOM_PARTIAL(x)
#define LIST_SKIP(x)
#define Skip_XX(x, y)

struct File_Riff {
    void Data_Parse();
};

#define break