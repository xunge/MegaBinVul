#include <list>
#include <memory>

class Common {
public:
  class AutoDebugRecursionChecker {
  public:
    AutoDebugRecursionChecker(void*) {}
  };
};

class ActiveClient {
public:
  int numActiveStreams();
  void close();
  int id();
};

class Host {
public:
  class Cluster {
  public:
    const char* name();
  };
  Cluster& cluster();
};

class ConnPoolImplBase {
protected:
  void* recursion_checker_;
  std::list<std::unique_ptr<ActiveClient>> ready_clients_;
  std::list<std::unique_ptr<ActiveClient>> connecting_clients_; 
  std::list<void*> pending_streams_;
  Host* host_;

public:
  void closeIdleConnectionsForDrainingPool();
};

#define ENVOY_LOG_EVENT(level, event, ...)