#include "client.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

#include "delegator/types/message_box.hpp"

using namespace nlohmann;

SOURIS_CORE_BEGIN_NAMESPACE

Client::Client(Controller *controller) : _controller(controller), _client() {
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

void Client::message_handler(const char *message, u32) {
    try {
        json json_message = nlohmann::json::parse(message);
        if (json_message["type"] == "message_box") {
            Delegator::MessageBox::handler({
                json_message["data"]["title"].get<json::string_t>().c_str(),
                json_message["data"]["message"].get<json::string_t>().c_str()
            });
        }
    } catch(nlohmann::detail::parse_error e) { std::cout << e.what() << std::endl; }
}

SOURIS_CORE_END_NAMESPACE
