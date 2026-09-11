
#ifndef APP_HPP
#define APP_HPP

#include "app_settings.hpp"

namespace mailman
{
    int app_parse(int argc, char* argv[], app_settings& settings);
    int app_launch(const app_settings& settings);
}; //namespace mailman

#endif

