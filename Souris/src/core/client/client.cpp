#include "client.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

using namespace nlohmann;

#include "delegator/types/client_path/client_path.hpp"
#include "delegator/types/process_start/process_start.hpp"
#include "delegator/types/stop/stop.hpp"

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

        json json_message = json::parse(message);
        json::string_t message_type = json_message["type"].get<json::string_t>();

        if (message_type == "client_path")
            Delegator::ClientPath::handler(_controller);
        else if (message_type == "process_start") {
            auto file = json_message["data"]["file"].get<json::string_t>();
            Delegator::ProcessStart::handler(_controller, file.c_str());
        } else if (message_type == "stop")
            Delegator::Stop::handler();

    } catch(const nlohmann::detail::parse_error &error) {
        std::cerr << error.what() << std::endl;
    } catch(const nlohmann::detail::type_error &error) {
        std::cerr << error.what() << std::endl;
    } catch(const std::runtime_error &error) {
        std::cerr << error.what() << std::endl;
    }
}

SOURIS_CORE_END_NAMESPACE
