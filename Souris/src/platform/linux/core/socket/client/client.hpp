#ifndef SOURIS_PLATFORM_LINUX_CORE_SOCKET_CLIENT_CLIENT_HPP
#define SOURIS_PLATFORM_LINUX_CORE_SOCKET_CLIENT_CLIENT_HPP

# include <functional>

# include "core/defines.hpp"

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
