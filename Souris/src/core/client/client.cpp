#include "client.hpp"

#include <cstdio>

#include "platform/platform.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

struct Client::SocketClientWrapper
{
    Platform::SocketClient handle;
};

Client::Client() : _socket_client(new SocketClientWrapper) {
    _socket_client->handle.set_recv_callback(std::bind(&Client::message_handler, this, std::placeholders::_1, std::placeholders::_2));
}

Client::Client(const char *address, int port) : _socket_client(new SocketClientWrapper) {
    _socket_client->handle.set_recv_callback(std::bind(&Client::message_handler, this, std::placeholders::_1, std::placeholders::_2));
    connect(address, port);
}

void Client::connect(const char *address, int port) {
    _socket_client->handle.connect(address, port);
}

int Client::listen() const {
    return _socket_client->handle.listen();
}

void Client::message_handler(const char *message, u32 length) {
    printf("message: \"%s\", size: %u\n", message, length);
}

SOURIS_CORE_END_NAMESPACE
