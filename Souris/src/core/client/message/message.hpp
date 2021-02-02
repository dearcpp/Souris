#ifndef SOURIS_CORE_CLIENT_MESSAGE_MESSAGE_HPP
#define SOURIS_CORE_CLIENT_MESSAGE_MESSAGE_HPP

# include "core/defines.hpp"

SOURIS_CORE_BEGIN_NAMESPACE

class Message
{
public:

    enum class Type
    {
        Print
    };

    virtual const char *get_name() const = 0;
    virtual Type get_type() const = 0;

};

# define SOURIS_MESSAGE_CLASS_TYPE(message_type) \
    virtual const char *get_name() const { return #message_type; } \
    virtual Type get_type() const { return message_type; } \
    static Type get_type_static() { return message_type; } \

class MessageDispatcher
{
public:

    MessageDispatcher(Message &event);

    template <class _type, class _function>
    bool dispatch(const _function &callback) const {
        if (_message.get_type() == _type::get_type_static()) {
            callback(static_cast<_type&>(_message));
            return true;
        }
        return false;
    }

    template <class _type>
    _type &get_message() const {
        return static_cast<_type&>(_message);
    }

protected:

    Message &_message;

};


SOURIS_CORE_END_NAMESPACE

#endif
