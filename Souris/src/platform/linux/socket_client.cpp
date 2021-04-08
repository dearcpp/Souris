#include <platform/platform.hpp>

#if defined(SOURIS_PLATFORM_LINUX)

# include <platform/tools/socket_client.hpp>

# include <cstring>
# include <stdexcept>

# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>

SOURIS_PLATFORM_BEGIN_NAMESPACE

SocketClient::SocketClient() {
    create();
}

SocketClient::SocketClient(const char *address, int port) {
    create(), connect(address, port);
}

void SocketClient::create() {
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw std::runtime_error("unable to create socket");
}

int SocketClient::connect(const char *address, int port) {
    sockaddr_in socket_address = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr { .s_addr = inet_addr(address) }
    };

    int result;

    if ((result = ::connect(_socket, (sockaddr*)&socket_address, sizeof(socket_address))) < 0)
        throw std::runtime_error("unable to create socket connection");

    return result;
}

void SocketClient::close() {
    if (::close(_socket) < 0)
        throw std::runtime_error("failed to close socket");
}

void SocketClient::send(const char *message, u32 length) const {
    if (_socket == -1)
        throw std::runtime_error("unable to send message with broken socket");

    if(::send(_socket, message, length, 0) < 0)
        throw std::runtime_error("failed to send data from socket");
}

void SocketClient::set_recv_callback(const RecvCallback &callback) {
    _recv_callback = callback;
}

int SocketClient::listen() const {
    while (1) {
        ssize_t reply_size = 32, old_reply_size = 0;
        char *reply = new char[reply_size]();
        while (1) {
            ssize_t result = ::recv(_socket, reply + old_reply_size, 32, 0);
            if (result <= 0)
                return result;

            if (result == 32) {
                old_reply_size = reply_size, reply_size += 32;
                char *new_reply = new char[reply_size]();
                memcpy(new_reply, reply, old_reply_size);
                delete[] reply;
                reply = new_reply;
            } else break;
        }
        _recv_callback(reply, reply_size), delete[] reply;
    }
}

SOURIS_PLATFORM_END_NAMESPACE

#endif
