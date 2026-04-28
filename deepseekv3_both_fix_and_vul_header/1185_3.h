#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

namespace boost {
namespace asio {
namespace ip {
    class tcp {};
} // namespace ip

class io_context {};
class acceptor {
public:
    acceptor(io_context&) {}
};
class signal_set {
public:
    signal_set(io_context&) {}
};
} // namespace asio
} // namespace boost

class Server {
public:
    Server(boost::asio::ip::tcp protocol, std::uint16_t port, const fs::path& doc_root);

private:
    void CheckDocRoot();
    void AddSignals();

    boost::asio::ip::tcp protocol_;
    std::uint16_t port_;
    fs::path doc_root_;
    boost::asio::io_context io_context_;
    boost::asio::acceptor acceptor_;
    boost::asio::signal_set signals_;
};