#define ARCHIVE_EXTRACT_TIME 1
#define ARCHIVE_EXTRACT_SECURE_NODOTDOT 2
#define ARCHIVE_EXTRACT_SECURE_SYMLINKS 4

struct LibarchivePlugin {
    int extractionFlags() const;
};