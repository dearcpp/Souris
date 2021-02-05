#ifndef SOURIS_CORE_CLIENT_MESSAGE_MESSAGE_HPP
#define SOURIS_CORE_CLIENT_MESSAGE_MESSAGE_HPP

# include "core/defines.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class MessageBase
{
public:

    enum class Type
    {
        MessageBox
    };

    virtual const char *get_name() const = 0;
    virtual Type get_type() const = 0;

};

SOURIS_CORE_END_NAMESPACE

# define SOURIS_MESSAGE_CLASS_TYPE(message_type) \
    virtual const char *get_name() const { return #message_type; } \
    virtual Type get_type() const { return message_type; } \
    static Type get_type_static() { return message_type; } \

#endif
