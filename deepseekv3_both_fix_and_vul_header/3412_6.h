#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>

typedef unsigned long Atom;

namespace base {
    class string16 {
    public:
        string16();
        string16(const string16&);
        string16(const char16_t*);
        const char* data() const;
    };
    string16 ASCIIToUTF16(const char*);
}

class GURL {
public:
    GURL();
    GURL(const std::string&);
    GURL(const base::string16&);
    bool SchemeIsFile() const;
};

namespace ui {
    class SelectionData {
    public:
        SelectionData(const void*);
        bool IsValid() const;
        Atom GetType() const;
        void AssignTo(base::string16*) const;
    };
    std::vector<Atom> GetURLAtomsFrom(const void*);
    void GetAtomIntersection(const std::vector<Atom>&, const std::vector<Atom>&, std::vector<Atom>*);
    std::vector<std::string> ParseURIList(const SelectionData&);
}

namespace Clipboard {
    extern const char kMimeTypeURIList[];
    extern const char kMimeTypeMozillaURL[];
}

const char kMimeTypeMozillaURL[] = "text/x-moz-url";

class OSExchangeData {
public:
    enum FilenameToURLPolicy {
        CONVERT_FILENAMES
    };
};

class FormatMap {
public:
    void* GetFirstOf(const std::vector<Atom>&) const;
};

class AtomCache {
public:
    Atom GetAtom(const char*) const;
};

class OSExchangeDataProviderAuraX11 {
private:
    AtomCache atom_cache_;
    FormatMap format_map_;
public:
    std::vector<Atom> GetTargets() const;
    bool GetURLAndTitle(OSExchangeData::FilenameToURLPolicy, GURL*, base::string16*) const;
    bool GetURLAndTitle(GURL*, base::string16*) const;
};

size_t Tokenize(const base::string16&, const base::string16&, std::vector<base::string16>*);