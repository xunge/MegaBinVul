#include <vector>
#include <cstddef>

typedef unsigned int IfdId;
enum {
    ifd0Id,
    ifd1Id,
    ifd2Id,
    ifd3Id,
    subImage1Id,
    subImage2Id,
    subImage3Id,
    subImage4Id,
    subImage5Id,
    subImage6Id,
    subImage7Id,
    subImage8Id,
    subImage9Id
};

enum TypeId { unsignedLong };

#define EXV_COUNTOF(arr) (sizeof(arr)/sizeof(arr[0]))

class TiffComponent {
public:
    virtual void accept(class TiffFinder& finder) = 0;
};

class TiffEntryBase {
public:
    virtual IfdId group() const = 0;
    virtual class Value* pValue() const = 0;
};

class Value {
public:
    virtual TypeId typeId() const = 0;
    virtual size_t count() const = 0;
    virtual long toLong() const = 0;
};

class TiffFinder {
public:
    TiffFinder(int, IfdId);
    TiffComponent* result() const;
};

typedef std::vector<IfdId> PrimaryGroups;

class TiffParserWorker {
public:
    void findPrimaryGroups(PrimaryGroups& primaryGroups, TiffComponent* pSourceDir);
};