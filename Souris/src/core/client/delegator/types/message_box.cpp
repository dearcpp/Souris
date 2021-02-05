#include "message_box.hpp"

#include "platform/tools/message_box.hpp"

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_DELEGATOR_BEGIN_NAMESPACE

void MessageBox::handler(const Message::MessageBox &message) {
    Platform::MessageBox(message.get_title(), message.get_message());
}

SOURIS_DELEGATOR_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
