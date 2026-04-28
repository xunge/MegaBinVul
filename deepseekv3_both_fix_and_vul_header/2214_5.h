#include <climits>
#include <cstdint>

#define SAL_MAX_UINT16 USHRT_MAX
#define sal_Bool bool
#define sal_True true
#define sal_False false
#define sal_uInt16 uint16_t
#define sal_uInt32 uint32_t
#define sal_Int16 int16_t
#define sal_Int32 int32_t

#define SAL_WARN_IF(cond, area, message) \
    do { if (cond) {} } while (0)

enum {
    STREAM_SEEK_TO_END,
    SVSTREAM_FILEFORMAT_ERROR,
    SVSTREAM_GENERALERROR,
    MM_ANISOTROPIC,
    W_META_SETWINDOWORG,
    W_META_SETWINDOWEXT,
    W_META_SETMAPMODE,
    W_META_MOVETO,
    W_META_LINETO,
    W_META_RECTANGLE,
    W_META_INTERSECTCLIPRECT,
    W_META_EXCLUDECLIPRECT,
    W_META_ELLIPSE,
    W_META_ROUNDRECT,
    W_META_ARC,
    W_META_PIE,
    W_META_CHORD,
    W_META_POLYGON,
    W_META_POLYPOLYGON,
    W_META_POLYLINE,
    W_META_SETPIXEL,
    W_META_TEXTOUT,
    W_META_EXTTEXTOUT,
    W_META_BITBLT,
    W_META_STRETCHBLT,
    W_META_DIBBITBLT,
    W_META_DIBSTRETCHBLT,
    W_META_STRETCHDIB,
    W_META_PATBLT,
    PATCOPY
};

class Point {
public:
    Point() {}
    Point(int, int) {}
};

class Size {
public:
    Size() {}
    Size(int, int) {}
    int Width() { return 0; }
    int Height() { return 0; }
};

class Rectangle {
public:
    sal_Int32 nLeft;
    sal_Int32 nTop;
    sal_Int32 nRight;
    sal_Int32 nBottom;
    
    Rectangle() : nLeft(0), nTop(0), nRight(0), nBottom(0) {}
    Rectangle(Point, Size) {}
    sal_Int32& Left() { return nLeft; }
    sal_Int32& Top() { return nTop; }
    sal_Int32& Right() { return nRight; }
    sal_Int32& Bottom() { return nBottom; }
    void SetPos(Point) {}
    void SetSize(Size) {}
};

class SvStream {
public:
    sal_uInt32 Tell() { return 0; }
    sal_uInt32 Seek(int) { return 0; }
    void Seek(sal_uInt32) {}
    bool GetError() { return false; }
    bool IsEof() { return false; }
    void SetError(int) {}
    bool good() { return true; }
    void SeekRel(int) {}
    SvStream& operator>>(sal_uInt16&) { return *this; }
    SvStream& operator>>(sal_uInt32&) { return *this; }
    SvStream& operator>>(sal_Int16&) { return *this; }
    SvStream& operator>>(sal_Int32&) { return *this; }
};

class WMFReader {
public:
    Point ReadYX();
    Point ReadPoint();
    Rectangle ReadRectangle();
    Size ReadYXExt();
    void ReadColor();
    void GetWinExtMax(Point, Rectangle&, sal_Int16);
    void GetWinExtMax(Rectangle, Rectangle&, sal_Int16);
    sal_Bool GetPlaceableBound(Rectangle&, SvStream*);
};