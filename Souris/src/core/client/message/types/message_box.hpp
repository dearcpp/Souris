#ifndef SOURIS_CORE_CLIENT_MESSAGE_TYPES_MESSAGE_BOX_HPP
#define SOURIS_CORE_CLIENT_MESSAGE_TYPES_MESSAGE_BOX_HPP

# include "core/client/message/message.hpp"

SOURIS_CORE_BEGIN_NAMESPACE
SOURIS_MESSAGE_BEGIN_NAMESPACE

class MessageBox : public MessageBase
{
public:

    MessageBox(const char *title, const char *message);

    const char *get_title() const;
    const char *get_message() const;

    SOURIS_MESSAGE_CLASS_TYPE(Type::MessageBox)

protected:

    const char *_title, *_message;

};

SOURIS_MESSAGE_END_NAMESPACE
SOURIS_CORE_END_NAMESPACE

#endif
