#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned int GLuint;
typedef int GLint;
typedef unsigned int GLenum;
typedef int GLsizei;
typedef uint32_t uint32;

#define DCHECK(cond) assert(cond)
#define GL_INVALID_OPERATION 0x0502

namespace error {
enum Error {
  kNoError,
  kOutOfBounds
};
}  // namespace error

template<typename T>
class SizedResult {
 public:
  void SetNumResults(GLsizei num_results) {}
  static uint32_t ComputeSize(GLsizei num_results) { return 0; }
  static uint32_t ComputeSizeFromBytes(GLsizei bytes) { return 0; }
  GLsizei size;
};

class GLES2Util {
 public:
  static GLsizei GetGLDataTypeSizeForUniforms(GLenum type) { return 0; }
};

class Program {
 public:
  struct UniformInfo {
    GLenum type;
  };
  bool IsValid() const { return false; }
  GLuint service_id() const { return 0; }
  const UniformInfo* GetUniformInfoByFakeLocation(
      GLint fake_location, GLint* real_location, GLint* array_index) const { return nullptr; }
};

class GLES2DecoderImpl {
 public:
  Program* GetProgramInfoNotShader(GLuint program_id, const char* function_name) { return nullptr; }
  template<typename T> T GetSharedMemoryAs(uint32_t shm_id, uint32_t shm_offset, uint32_t size) { 
    return nullptr;
  }
  void LOCAL_SET_GL_ERROR(GLenum error, const char* function_name, const char* description) {}
  
  bool GetUniformSetup(GLuint program_id, GLint fake_location,
                      uint32 shm_id, uint32 shm_offset,
                      error::Error* error, GLint* real_location,
                      GLuint* service_id, void** result_pointer,
                      GLenum* result_type, GLsizei* result_size);
  
  bool GetUniformSetup(GLuint program_id, GLint fake_location,
                      uint32 shm_id, uint32 shm_offset,
                      error::Error* error, GLint* real_location,
                      GLuint* service_id, void** result_pointer,
                      GLenum* result_type);
};