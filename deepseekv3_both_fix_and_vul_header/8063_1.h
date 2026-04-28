#include <cstddef>
#include <cstdlib>

#define UNREACHABLE() abort()

enum VisitMode {
  VISIT_ONLY_STRONG_ROOT_LIST,
  VISIT_ONLY_STRONG,
  VISIT_ONLY_STRONG_FOR_SERIALIZATION,
  VISIT_ALL_IN_SCAVENGE,
  VISIT_ALL_IN_SWEEP_NEWSPACE,
  VISIT_ALL
};

class ObjectVisitor {
public:
  virtual void VisitPointers(void** start, void** end) = 0;
  virtual void Synchronize(int id) = 0;
};

class VisitorSynchronization {
public:
  static const int kStrongRootList = 0;
  static const int kBootstrapper = 1;
  static const int kTop = 2;
  static const int kRelocatable = 3;
  static const int kDebug = 4;
  static const int kCompilationCache = 5;
  static const int kHandleScope = 6;
  static const int kBuiltins = 7;
  static const int kDispatchTable = 8;
  static const int kGlobalHandles = 9;
  static const int kEternalHandles = 10;
  static const int kThreadManager = 11;
  static const int kStrongRoots = 12;
};

class StrongRootsList {
public:
  void** start;
  void** end;
  StrongRootsList* next;
};

class Isolate {
public:
  class Bootstrapper {
  public:
    void Iterate(ObjectVisitor* v);
  };
  class Debug {
  public:
    void Iterate(ObjectVisitor* v);
  };
  class CompilationCache {
  public:
    void Iterate(ObjectVisitor* v);
  };
  class HandleScopeImplementer {
  public:
    void Iterate(ObjectVisitor* v);
  };
  class Builtins {
  public:
    void IterateBuiltins(ObjectVisitor* v);
  };
  class Interpreter {
  public:
    void IterateDispatchTable(ObjectVisitor* v);
  };
  class GlobalHandles {
  public:
    void IterateStrongRoots(ObjectVisitor* v);
    void IterateNewSpaceStrongAndDependentRoots(ObjectVisitor* v);
    void IterateAllRoots(ObjectVisitor* v);
  };
  class EternalHandles {
  public:
    void IterateNewSpaceRoots(ObjectVisitor* v);
    void IterateAllRoots(ObjectVisitor* v);
  };
  class ThreadManager {
  public:
    void Iterate(ObjectVisitor* v);
  };

  Bootstrapper* bootstrapper();
  Debug* debug();
  CompilationCache* compilation_cache();
  HandleScopeImplementer* handle_scope_implementer();
  Builtins* builtins();
  Interpreter* interpreter();
  GlobalHandles* global_handles();
  EternalHandles* eternal_handles();
  ThreadManager* thread_manager();

  void Iterate(ObjectVisitor* v);
  void IterateDeferredHandles(ObjectVisitor* v);
};

class Relocatable {
public:
  static void Iterate(Isolate* isolate, ObjectVisitor* v);
};

class SerializerDeserializer {
public:
  static void Iterate(Isolate* isolate, ObjectVisitor* v);
};

class FixStaleLeftTrimmedHandlesVisitor : public ObjectVisitor {
public:
  explicit FixStaleLeftTrimmedHandlesVisitor(void* heap) {}
  void VisitPointers(void** start, void** end) override {}
  void Synchronize(int id) override {}
};

class Heap {
private:
  void** roots_;
  static const size_t kStrongRootListLength;
  StrongRootsList* strong_roots_list_;
  Isolate* isolate_;

public:
  void IterateStrongRoots(ObjectVisitor* v, VisitMode mode);
};