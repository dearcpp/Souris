#ifndef SOURIS_CORE_CLIENT_CLIENT_HPP
#define SOURIS_CORE_CLIENT_CLIENT_HPP

# include "platform/tools/socket_client.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class Controller;

class Client
{
public:

    Client(Controller *controller);

    void connect(const char *address, int port);

    void send(const char *message, u32 length) const;

    int listen() const;

protected:

    Controller *_controller;
    Platform::SocketClient _client;

    void message_handler(const char *message, u32 length);

};

SOURIS_CORE_END_NAMESPACE

#endif
