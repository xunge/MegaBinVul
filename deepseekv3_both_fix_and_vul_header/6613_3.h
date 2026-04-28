#include <string>
#include <utility>
#include <istream>
#include <ostream>

class ZipLocalFileHeader {
public:
    bool isDirectory() const;
    std::string getFileName() const;
    size_t getUncompressedSize() const;
    bool searchCRCAndSizesAfterData() const;
};

class ZipInputStream : public std::istream {
public:
    ZipInputStream(std::istream&, const ZipLocalFileHeader&, bool);
    bool crcValid() const;
};

class ZipException : public std::exception {
public:
    ZipException(const std::string&);
    ZipException(const std::string&, const std::string&);
};

class ZipCommon {
public:
    static bool isValidPath(const std::string&);
};

class Poco {
public:
    class Path {
    public:
        Path(const std::string&);
        Path(const std::string&, const std::string&);
        Path(const std::string&, const Path&);
        void makeDirectory();
        void makeFile();
        std::string toString() const;
        Path parent() const;
        int depth() const;
        std::string getFileName() const;
    };
    
    class File {
    public:
        File(const Path&);
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
    
    class Exception : public std::exception {
    public:
        std::string displayText() const;
    };
    
    class StreamCopier {
    public:
        static void copyStream(std::istream&, std::ostream&);
    };
};

class Decompress {
public:
    bool _flattenDirs;
    bool _keepIncompleteFiles;
    std::string _outDir;
    
    struct {
        template<typename T>
        void notify(Decompress*, const std::pair<const ZipLocalFileHeader, const T>&) {}
    } EError, EOk;

    bool handleZipEntry(std::istream& zipStream, const ZipLocalFileHeader& hdr);
};