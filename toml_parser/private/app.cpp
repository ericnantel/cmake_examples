
#include "app.hpp"
#include "pch.hpp"

#include <iostream>

void app_init(std::string_view filepath)
{
    if (!filepath.empty() && std::filesystem::exists(filepath))
    {
        auto config = toml::parse_file(filepath);
        auto message = config["log"]["message"].value_or("no message");
        auto affiche = config["log"]["affiche"].value_or(false);
        auto width = config["log"]["width"].value_or(500);

        std::cout << message << "," << affiche << "," << width << std::endl;
    }
    else
    {
        std::cout << "Hello World " << std::endl;
    }
}
