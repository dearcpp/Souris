#ifndef SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP
#define SOURIS_CORE_CLIENT_DELEGATOR_DELEGATOR_HPP

# include "core/defines.hpp"
# include "core/controller/controller.hpp"

# define SOURIS_DECLARE_DELEGATOR(delegator_name, delegator_message, delegator_parameters) \
    class delegator_name \
    { \
    public: \
        static void handler(delegator_parameters); \
    }; \

#endif
