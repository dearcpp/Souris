#ifndef SOURIS_PLATFORM_TOOLS_SOCKET_CLIENT_HPP
#define SOURIS_PLATFORM_TOOLS_SOCKET_CLIENT_HPP

# include <core/defines.hpp>
# include <functional>

SOURIS_PLATFORM_BEGIN_NAMESPACE

class SocketClient
{
public:

    using Handle = int;
    using RecvCallback = std::function<void(const char*, u32)>;

    SocketClient();
    SocketClient(const char *address, int port);

    void create();
    int connect(const char *address, int port);
    void close();

    void send(const char *message, u32 length) const;

    void set_recv_callback(const RecvCallback &callback);

    int listen() const;

protected:

    Handle _socket;
    RecvCallback _recv_callback;

};

SOURIS_PLATFORM_END_NAMESPACE

#endif
