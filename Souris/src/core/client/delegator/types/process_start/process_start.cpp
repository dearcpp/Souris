#include "process_start.hpp"

#include "core/utilities.hpp"
#include "platform/tools/process.hpp"

using namespace nlohmann;

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_DELEGATOR_BEGIN_NAMESPACE

void ProcessStart::handler(const Controller *controller, const json &data) {
    Platform::Process process(data["file"].get<json::string_t>().c_str());
    auto result = process.read_output();
    controller->get_client().send(result.c_str(), result.size());
}

SOURIS_DELEGATOR_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
