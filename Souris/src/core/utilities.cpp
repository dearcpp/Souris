#include "utilities.hpp"

#include <cctype>

bool is_number(const char *str) {
    char *i = const_cast<char*>(str);
    while (*i != 0 && std::isdigit(*i)) ++i;
    return i != str && *i == 0;
}
