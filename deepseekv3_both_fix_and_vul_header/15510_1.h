#include <sys/epoll.h>
#include <unistd.h>
#include <stdio.h>

#define LOG_WARN(...) printf(__VA_ARGS__)
#define LOG_ERROR(...) printf(__VA_ARGS__)
#define READ_CLOSE (-1)
#define READ_CONTINUE 0
#define READ_OVER 1
#define CONTEXT_READ_OVER 2

struct EpollContext {
    int fd;
    int _ctx_status;
};

class EpollSocket {
public:
    int handle_readable_event(struct epoll_event &event);
private:
    int _epollfd;
    class Watcher {
    public:
        virtual int on_readable(int epollfd, struct epoll_event &event) = 0;
    };
    Watcher* _watcher;
    int close_and_release(struct epoll_event &event);
};