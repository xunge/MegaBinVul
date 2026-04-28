#include <memory>

namespace Network {
enum class ConnectionEvent {
  LocalClose,
  RemoteClose,
  Connected
};
class Connection {
public:
  enum class State {
    Closed
  };
  State state() const;
};
}  // namespace Network

namespace Tcp {
namespace ConnectionPool {
class ConnectionData {
public:
  Network::Connection& connection();
};
using ConnectionDataPtr = std::unique_ptr<ConnectionData>;
}  // namespace ConnectionPool
}  // namespace Tcp

class Upstream {
public:
  Tcp::ConnectionPool::ConnectionDataPtr onDownstreamEvent(Network::ConnectionEvent event);
};

class GenericConnPool {
public:
  ~GenericConnPool();
};

class ReadCallbacks {
public:
  Network::Connection& connection();
  class UpstreamHost* upstreamHost();
};

class Config {
public:
  class DrainManager& drainManager();
  class SharedConfig& sharedConfig();
};

class UpstreamCallbacks {};
class IdleTimer {};
class UpstreamHost {};

class SharedConfig {};

class DrainManager {
public:
  void add(SharedConfig& config, Tcp::ConnectionPool::ConnectionDataPtr&& conn_data,
           std::unique_ptr<UpstreamCallbacks>&& callbacks, std::unique_ptr<IdleTimer>&& timer,
           UpstreamHost* host);
};

class Filter {
public:
  void onDownstreamEvent(Network::ConnectionEvent event);
  void disableIdleTimer();

private:
  bool downstream_closed_;
  std::unique_ptr<Upstream> upstream_;
  std::unique_ptr<GenericConnPool> generic_conn_pool_;
  ReadCallbacks* read_callbacks_;
  Config* config_;
  std::unique_ptr<UpstreamCallbacks> upstream_callbacks_;
  std::unique_ptr<IdleTimer> idle_timer_;
};

#define ENVOY_CONN_LOG(level, ...)