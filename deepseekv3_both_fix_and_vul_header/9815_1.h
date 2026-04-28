#include <map>

#define NOTREACHED()

class MessagePortDispatcher {
public:
    void OnQueueMessages(int message_port_id);
};

struct WorkerProcessMsg_MessagesQueued {
    explicit WorkerProcessMsg_MessagesQueued(int route_id);
};

class Sender {
public:
    void Send(WorkerProcessMsg_MessagesQueued* msg);
};

struct MessagePort {
    bool queue_messages;
    int route_id;
    Sender* sender;
};

std::map<int, MessagePort> message_ports_;