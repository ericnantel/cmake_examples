
#include "app.hpp"

#include <cstdlib>

int main(int argc, char* argv[])
{
    int result = 0;
    mailman::app_settings settings;
    result = mailman::app_parse(argc, argv, settings);
    result = mailman::app_launch(settings);
    return EXIT_SUCCESS;
}
