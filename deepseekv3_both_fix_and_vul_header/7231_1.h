#include <memory>

namespace Network {
enum class ConnectionEvent {
  RemoteClose,
  LocalClose
};

enum class ConnectionCloseType {
  FlushWrite
};

class Connection {
public:
  enum class State {
    Open
  };
  State state();
  void close(ConnectionCloseType);
};
} // namespace Network

namespace StreamInfo {
enum class ResponseFlag {
  UpstreamConnectionFailure
};
class StreamInfo {
public:
  void setResponseFlag(ResponseFlag);
};
} // namespace StreamInfo

namespace Upstream {
namespace Outlier {
enum class Result {
  LocalOriginConnectFailed
};
class Detector {
public:
  void putResult(Result);
};
} // namespace Outlier

class Host {
public:
  Outlier::Detector& outlierDetector();
};
} // namespace Upstream

class Filter {
protected:
  bool connecting_;
  bool downstream_closed_;
  std::unique_ptr<Network::Connection> upstream_;
  StreamInfo::StreamInfo getStreamInfo();
  void disableIdleTimer();
  void initializeUpstreamConnection();
  void onUpstreamEvent(Network::ConnectionEvent event);

  struct ReadCallbacks {
    Network::Connection& connection();
    Upstream::Host* upstreamHost();
  };
  ReadCallbacks* read_callbacks_;
};