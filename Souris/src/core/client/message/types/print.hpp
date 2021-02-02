#ifndef SOURIS_CORE_CLIENT_MESSAGE_TYPES_PRINT_HPP
#define SOURIS_CORE_CLIENT_MESSAGE_TYPES_PRINT_HPP

# include "core/client/message/message.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class MessagePrint : public Message
{
public:

    MessagePrint(const char *message);

    const char *get_message() const;

    SOURIS_MESSAGE_CLASS_TYPE(Type::Print)

protected:

    const char *_message;

};

SOURIS_CORE_END_NAMESPACE

#endif
