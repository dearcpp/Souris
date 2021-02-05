#ifndef SOURIS_PLATFORM_TOOLS_MESSAGE_BOX_HPP
#define SOURIS_PLATFORM_TOOLS_MESSAGE_BOX_HPP

# include "platform/platform.hpp"

# if defined(SOURIS_PLATFORM_LINUX)
#  if __has_include(<X11/X.h>)
#   include "platform/linux/interface/x11/message_box/message_box.hpp"
#  endif
# endif

#endif
