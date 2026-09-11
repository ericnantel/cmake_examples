
#ifndef APP_SETTINGS_HPP
#define APP_SETTINGS_HPP

namespace mailman
{
    struct app_settings
    {
        struct window_settings
        {
            bool fullscreen = false;
            int width = 720;
            int height = 480;
        } window;

        struct graphics_settings
        {
            bool vsync = true;
        } graphics;

        static constexpr const char* default_path = "settings/app.toml";
    };
}; //namespace mailman

#endif
