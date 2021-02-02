#include "print.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

MessagePrint::MessagePrint(const char *message) : _message(message) { }

const char *MessagePrint::get_message() const {
    return _message;
}

SOURIS_CORE_END_NAMESPACE
