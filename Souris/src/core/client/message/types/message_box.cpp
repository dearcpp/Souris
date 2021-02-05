#include "message_box.hpp"

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_MESSAGE_BEGIN_NAMESPACE

MessageBox::MessageBox(const char *title, const char *message) : _title(title), _message(message) { }

const char *MessageBox::get_title() const {
    return _title;
}

const char *MessageBox::get_message() const {
    return _message;
}

SOURIS_MESSAGE_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE
