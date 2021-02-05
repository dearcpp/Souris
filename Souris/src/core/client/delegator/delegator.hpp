#ifndef SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP
#define SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP

# include "core/defines.hpp"

# define SOURIS_DECLARE_DELEGATOR(delegator_name, delegator_message) \
    SOURIS_DELEGATOR_BEGIN_NAMESPACE \
    class delegator_name \
    { \
    public: \
        static void handler(const delegator_message &message); \
    }; \
    SOURIS_DELEGATOR_END_NAMESPACE \

#endif
