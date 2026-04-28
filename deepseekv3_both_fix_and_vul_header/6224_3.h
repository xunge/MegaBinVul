#include <vector>
#include <cstring>
#include <cstdint>
#include <string>
#include <iostream>

using int64 = int64_t;

struct Tensor {
    int dtype() const { return 0; }
    void AsProtoTensorContent(void*) const {}
    struct Shape {
        void AsProto(void*) const {}
    };
    Shape shape() const { return Shape(); }
};

struct TensorProto {
    size_t ByteSizeLong() const { return 0; }
    void SerializeToArray(char*, size_t) const {}
};

struct TensorBuffer {
    const void* data() const { return nullptr; }
    size_t size() const { return 0; }
};

struct DMAHelper {
    static const TensorBuffer* buffer(const Tensor*) { return nullptr; }
};

struct CompressedComponentMetadata {
    void set_dtype(int) {}
    void* mutable_tensor_shape() { return nullptr; }
    void set_tensor_size_bytes(size_t) {}
    size_t tensor_size_bytes() const { return 0; }
};

struct CompressedElement {
    struct MetadataList {
        CompressedComponentMetadata* Add() { return nullptr; }
    };
    MetadataList* mutable_component_metadata() { return nullptr; }
    void* mutable_data() { return nullptr; }
    struct DataContainer {
        size_t size() const { return 0; }
    };
    DataContainer data() { return DataContainer(); }
};

struct Status {
    static Status OK() { return Status(); }
};

namespace errors {
    Status Internal(const char*) { return Status(); }
}

namespace port {
    bool Snappy_Compress(const char*, size_t, void*) { return false; }
}

class tstring : public std::string {
public:
    void resize_uninitialized(size_t) {}
    char* mdata() { return data(); }
};

bool DataTypeCanUseMemcpy(int) { return false; }

#define DCHECK_EQ(a, b) ((void)0)
#define VLOG(level) if (false) std::cout