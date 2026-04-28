#include <sys/stat.h>
#include <unistd.h>
#include <string>

class RString {
public:
    RString(const std::string& s = "") : m_s(s) {}
    RString operator+(const char* rhs) const { return RString(m_s + rhs); }
    const std::string& GetValue() const { return m_s; }
    operator const char*() const { return m_s.c_str(); }
private:
    std::string m_s;
};

class RageException {
public:
    static void Throw(const char* fmt, ...);
};

class RageFileManagerUtil {
public:
    static RString sInitialWorkingDirectory;
};

class FileManager {
public:
    void Mount(const char* type, const RString& path, const char* mountpoint);
};

class ArchHooks {
public:
    static void MountInitialFilesystems(const RString& sDirOfExecutable);
};

extern FileManager* FILEMAN;
extern RString COULDNT_FIND_SONGS;