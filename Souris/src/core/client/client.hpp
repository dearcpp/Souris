#ifndef SOURIS_CORE_CLIENT_CLIENT_HPP
#define SOURIS_CORE_CLIENT_CLIENT_HPP

# include "core/defines.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class Client
{
protected:

    struct SocketClientWrapper;

public:

    Client();
    Client(const char *address, int port);

    void connect(const char *address, int port);

    void send(const char *message, u32 length) const;

    int listen() const;

protected:

    void message_handler(const char *message, u32 length);

    SocketClientWrapper *_socket_client;

};

SOURIS_CORE_END_NAMESPACE

#endif
