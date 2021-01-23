#ifndef SOURIS_CORE_CLIENT_CLIENT_HPP
#define SOURIS_CORE_CLIENT_CLIENT_HPP

# include "core/int_types.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class Client
{
protected:

    struct SocketClientWrapper;

public:

    Client(const char *address, int port);

    int exec();

protected:

    void message_handler(const char *message, u32 length);

    int _server_port;
    const char *_server_address;

    SocketClientWrapper *_socket_client;

};

SOURIS_CORE_END_NAMESPACE

#endif
