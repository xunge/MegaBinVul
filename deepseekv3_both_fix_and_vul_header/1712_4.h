#include <cassert>
#include <cstdint>

struct LookupTableEntry {
  bool isValid() const;
  bool isStringPrim() const;
  bool isLazyASCII() const;
  bool isLazyUTF16() const;
  uint32_t getHash() const;
  uint32_t getStringPrim() const;
  const void *getLazyASCIIRef() const;
  const void *getLazyUTF16Ref() const;
};

class IdentifierTable {
public:
  LookupTableEntry& getLookupTableEntry(uint32_t val);
};

class CompactTable {
public:
  CompactTable(uint32_t capacity, uint32_t scale);
  void swap(CompactTable &other);
  uint32_t size() const;
  bool isValid(uint32_t idx) const;
  uint32_t get(uint32_t idx) const;
  void set(uint32_t idx, uint32_t val);
  uint32_t getCurrentScale() const;
};

class IdentifierHashTable {
public:
  uint32_t capacity() const;
  uint32_t lookupString(uint32_t str, uint32_t hash, bool knownUnique);
  uint32_t lookupString(const void *str, uint32_t hash, bool knownUnique);
  void growAndRehash(uint32_t newCapacity);
  uint32_t nonEmptyEntryCount_;
  uint32_t size_;
  CompactTable table_;
  IdentifierTable* identifierTable_;
};

namespace llvh {
  bool isPowerOf2_32(uint32_t value);
}

#define LLVM_UNLIKELY(x) (x)
void hermes_fatal(const char *msg);