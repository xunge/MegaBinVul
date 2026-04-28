#include <vector>
#include <cstdint>

inline bool IsExif(const std::vector<uint8_t>& exif, bool* bigendian);
inline uint32_t LoadBE32(const uint8_t* p);
inline uint32_t LoadLE32(const uint8_t* p);
inline uint16_t LoadBE16(const uint8_t* p);
inline uint16_t LoadLE16(const uint8_t* p);