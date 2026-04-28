#include <iostream>
#include <string>
#include <cstdint>

#define DVLOG(level) std::cerr

namespace IPC {
class Message {
 public:
  uint32_t type() const;
  int32_t routing_id() const;
};
}  // namespace IPC

enum WebSocketHostState {
  WEBSOCKET_HOST_ALIVE,
  WEBSOCKET_HOST_DELETED
};

class WebSocketDispatcherHost {
 public:
  bool Send(IPC::Message* message);
  void DeleteWebSocketHost(int32_t routing_id);
  WebSocketHostState SendOrDrop(IPC::Message* message);
};

// 添加类型别名以确保兼容性
typedef uint32_t uint32;
typedef int32_t int32;