#include "app.hpp"
#include "pch.hpp"

int main(int argc, char* argv[])
{
    std::string_view filepath = "settings/app.toml";
    app_init(filepath);
    return EXIT_SUCCESS;
}
