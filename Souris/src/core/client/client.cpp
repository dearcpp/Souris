#include "client.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

#include "message/message.hpp"
#include "message/types/print.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

Client::Client() : _client() {
    _client.set_recv_callback(std::bind(&Client::message_handler, this, std::placeholders::_1, std::placeholders::_2));
}

void Client::connect(const char *address, int port) {
    _client.connect(address, port);
}

void Client::send(const char *message, u32 length) const {
    _client.send(message, length);
}

int Client::listen() const {
    return _client.listen();
}

// @note: ok. next task: implement a normal message handling interface

void Client::message_handler(const char *message, u32) {
    try {
        nlohmann::json json_message = nlohmann::json::parse(message);
        if (json_message["type"] == "print")
            std::cout << json_message["text"].get<nlohmann::json::string_t>().c_str() << std::endl;
    } catch(nlohmann::detail::parse_error e) { std::cout << e.what() << std::endl; }
}

SOURIS_CORE_END_NAMESPACE
