#include <string>
#include <utility>
#include <istream>
#include <exception>
#include <sstream>

struct ZipLocalFileHeader {
    bool isDirectory() const;
    std::string getFileName() const;
    size_t getUncompressedSize() const;
    bool searchCRCAndSizesAfterData() const;
};

struct ZipInputStream : public std::istream {
    ZipInputStream(std::istream&, const ZipLocalFileHeader&, bool);
    bool crcValid() const;
};

struct ZipException : public std::exception {
    ZipException(const std::string&);
};

struct ZipCommon {
    static bool isValidPath(const std::string&);
};

namespace Poco {
    class Path {
    public:
        Path(const std::string&);
        Path(const std::string&, const std::string&);
        Path(const Path&, const Path&);
        void makeDirectory();
        void makeFile();
        std::string toString() const;
        std::string getFileName() const;
        Path parent() const;
        int depth() const;
    };
    
    class File {
    public:
        File(const Path&);
        File(const std::string&);
        bool exists() const;
        bool isFile() const;
        void createDirectories();
        void remove();
        size_t getSize() const;
    };
    
    class FileOutputStream : public std::ostream {
    public:
        FileOutputStream(const std::string&);
        void close();
    };
    
    class Exception {
    public:
        std::string displayText() const;
    };
    
    namespace StreamCopier {
        void copyStream(std::istream&, std::ostream&);
    };
}

class Decompress {
public:
    bool _flattenDirs;
    bool _keepIncompleteFiles;
    std::string _outDir;
    
    struct {
        void notify(Decompress*, const std::pair<const ZipLocalFileHeader&, const std::string&>) {}
    } EError;
    
    struct {
        void notify(Decompress*, const std::pair<const ZipLocalFileHeader&, const Poco::Path&>) {}
    } EOk;

    bool handleZipEntry(std::istream& zipStream, const ZipLocalFileHeader& hdr);
};