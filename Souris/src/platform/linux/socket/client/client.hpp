#ifndef SOURIS_PLATFORM_LINUX_SOCKET_CLIENT_CLIENT_HPP
#define SOURIS_PLATFORM_LINUX_SOCKET_CLIENT_CLIENT_HPP

# include "core/int_types.hpp"

# include <functional>

SOURIS_CORE_BEGIN_NAMESPACE

class SocketClient
{
public:

    using Handle = int;
    using RecvCallback = std::function<void(const char*, u32)>;

    SocketClient();
    SocketClient(const char *address, int port);

    void create();
    void connect(const char *address, int port);
    void close();

    void send(const char *message, u32 length);

    void set_recv_callback(const RecvCallback &callback);

    int listen();

protected:

    Handle _socket;
    RecvCallback _recv_callback;

};

SOURIS_CORE_END_NAMESPACE

#endif
