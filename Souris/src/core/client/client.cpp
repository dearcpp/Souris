#include "client.hpp"

#include "platform/linux/socket/client/client.hpp"

#include <cstdio>

SOURIS_CORE_BEGIN_NAMESPACE

struct Client::SocketClientWrapper
{
    SocketClient handle;
};

Client::Client(const char *address, int port) : _server_port(port), _server_address(address), _socket_client(new SocketClientWrapper) {
    _socket_client->handle.set_recv_callback(std::bind(&Client::message_handler, this, std::placeholders::_1, std::placeholders::_2));
}

int Client::exec() {
    _socket_client->handle.connect(_server_address, _server_port);
    return _socket_client->handle.listen();
}

void Client::message_handler(const char *message, u32 length) {
    printf("message: \"%s\", size: %u\n", message, length);
}

SOURIS_CORE_END_NAMESPACE
