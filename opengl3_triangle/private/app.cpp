#include "pch.hpp"

#include "app.hpp"
#include "glincludes.hpp"

#include <iostream>

namespace mailman
{

    static void on_error(int error, const char* description)
    {
        std::cerr << "Error: " << description << std::endl;
    }

    static void on_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        // std::cout << key << scancode << action << mods << std::endl;

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    static void on_mouse(GLFWwindow* window, int button, int action, int mods)
    {
        std::cout << button << action << mods << std::endl;
    }

    static void on_scroll(GLFWwindow* window, double xoffset, double yoffset)
    {
        std::cout << xoffset << yoffset << std::endl;
    }

    static void on_cursor_move(GLFWwindow* window, double xpos, double ypos)
    {
        std::cout << xpos << ypos << std::endl;
    }

    static void on_cursor_enter(GLFWwindow* window, int entered)
    {
        std::cout << entered << std::endl;

        if (entered)
        {
            //entered the content area of the window
        }
        else
        {
            //left the content area of the window
        }
    }

    static void on_size(GLFWwindow* window, int width, int height)
    {
        std::cout << "on size " << width << height << std::endl;

        glViewport(0, 0, width, height);
    }

    static void on_scale(GLFWwindow* window, float xscale, float yscale)
    {
        std::cout << "on scale " << xscale << yscale << std::endl;
    }

    static void on_move(GLFWwindow* window, int xpos, int ypos)
    {
        std::cout << "on move " << xpos << ypos << std::endl;
    }

    static void on_iconify(GLFWwindow* window, int iconified)
    {
        std::cout << "on iconify " << iconified << std::endl;

        if (iconified)
        {
            //minimize ..
        }
        else
        {
            //restore ..
        }
    }

    static void on_maximize(GLFWwindow* window, int maximized)
    {
        std::cout << "on maximize " << maximized << std::endl;

        if (maximized)
        {
            //maximize ..
        }
        else
        {
            //restore ..
        }
    }

    static void on_focus(GLFWwindow* window, int focused)
    {
        std::cout << "on focus " << focused << std::endl;

        if (focused)
        {
            //gain focus ..
        }
        else
        {
            //lost focus ..
        }
    }

    static void on_close(GLFWwindow* window)
    {
        std::cout << "closing window.." << std::endl;
    }

    int app_parse(int argc, char* argv[], app_settings& settings)
    {
        std::cout << "app parse.." << std::endl;

        std::string_view config_path = app_settings::default_path;
        for (auto i = 1; i < argc; ++i)
        {
            std::string arg(argv[i]);
            std::cout << arg << std::endl;
            if (arg == "--config")
            {
                if (i + 1 < argc)
                {
                    std::string custom_path(argv[i + 1]);
                    config_path = custom_path;
                }
                else
                {
                    std::cout << "missing --config param value" << std::endl;
                }
            }
        }

        //deserializing app settings
        if (!config_path.empty() && std::filesystem::exists(config_path))
        {
            using namespace std::literals;
            auto config = toml::parse_file(config_path);

            //deserializing window settings
            settings.window.fullscreen = config["window"]["fullscreen"].value_or(settings.window.fullscreen);
            settings.window.width = config["window"]["width"].value_or(settings.window.width);
            settings.window.height = config["window"]["height"].value_or(settings.window.height);

            //deserializing graphics settings
            settings.graphics.vsync = config["graphics"]["vsync"].value_or(settings.graphics.vsync);
        }
        else if (!config_path.empty())
        {
            std::cout << "invalid config path " << config_path << std::endl;
        }

        std::cout << settings.window.fullscreen << settings.window.width << settings.window.height << std::endl;
        std::cout << settings.graphics.vsync << std::endl;

        return 0;
    }

    int app_launch(const app_settings& settings)
    {
        std::cout << "app launch.." << std::endl;

        glfwSetErrorCallback(on_error);

        if (glfwInit() != GLFW_TRUE)
        {
            return -1;
        }

        const bool fullscreen = settings.window.fullscreen;
        const int width = settings.window.width;
        const int height = settings.window.height;

        const bool vsync = settings.graphics.vsync;

        //NOTE: However would be nice to get the right monitor
        //Especially if using a tiling window manager
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* video_mode = glfwGetVideoMode(monitor);
        const int screen_width = video_mode->width;
        const int screen_height = video_mode->height;

        int window_color_red_bits = video_mode->redBits;
        int window_color_green_bits = video_mode->greenBits;
        int window_color_blue_bits = video_mode->blueBits;
        int window_refresh_rate = video_mode->refreshRate;
        int window_width = fullscreen ? screen_width : width;
        int window_height = fullscreen ? screen_height : height;
        const char* window_title = "mailman";

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);

        glfwWindowHint(GLFW_RED_BITS, window_color_red_bits);
        glfwWindowHint(GLFW_GREEN_BITS, window_color_green_bits);
        glfwWindowHint(GLFW_BLUE_BITS, window_color_blue_bits);
        glfwWindowHint(GLFW_ALPHA_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_DEPTH_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_STENCIL_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_ACCUM_RED_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_ACCUM_GREEN_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_ACCUM_BLUE_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_STEREO, GLFW_FALSE);
        glfwWindowHint(GLFW_SAMPLES, GLFW_DONT_CARE);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
        glfwWindowHint(GLFW_REFRESH_RATE, window_refresh_rate);

        //NOTE: if Vulkan, no need to create a context
        //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        //then you would create a Vulkan window surface
        //VkSurfaceKHR surface;
        //glfwCreateWindowSurface(instance, window, null, &surface);

        GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, fullscreen ? monitor : nullptr, nullptr);
        if (window == nullptr)
        {
            return -1;
        }

        //glfwRawMouseMotionSupported() glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
        //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        //glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

        glfwSetKeyCallback(window, on_key);
        glfwSetMouseButtonCallback(window, on_mouse);
        glfwSetScrollCallback(window, on_scroll);
        glfwSetCursorPosCallback(window, on_cursor_move);
        glfwSetCursorEnterCallback(window, on_cursor_enter);
        //glfwSetCharCallback(window, on_type); //unsigned int codepoint
        glfwSetFramebufferSizeCallback(window, on_size);
        glfwSetWindowContentScaleCallback(window, on_scale);
        glfwSetWindowPosCallback(window, on_move);
        glfwSetWindowIconifyCallback(window, on_iconify);
        glfwSetWindowMaximizeCallback(window, on_maximize);
        glfwSetWindowFocusCallback(window, on_focus);
        glfwSetWindowCloseCallback(window, on_close);

        glfwMakeContextCurrent(window);
        //glfwSetWindowPos(..);
        //glfwSetWindowTitle(..)
        // glfwSetWindowIcon(window, 0, nullptr);
        //visibility, opacity, focus, size limit, aspect ratio
        //request attention, damage and refresh, window attributes
        //you can minimize, restore, switch monitor, toggle fullscreen
        //you can even know when a monitor connected or disconnected.
        //you can also create a custom cursor and set as current
        // glfwSetCursor(window, nullptr);
        //you can query if cursor is hovering the window
        //glfwGetWindowAttrib(window, GLFW_HOVERED);
        //you can know when a joystick is connected or disconnected
        //read its axes, buttons, etc. including gamepad.
        //you can also read from clipboard..
        //you can also read drop paths (files or directories) ..

        const int vsync_count = vsync ? 1 : 0;
        glfwSwapInterval(vsync_count);

        //base time (optional but perhaps we should reset when simulation is reset)
        //glfwSetTime(0.0);

        int glad_version = gladLoadGL(glfwGetProcAddress);
        if (glad_version == 0)
        {
            return -1;
        }

        std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(glad_version) << "." << GLAD_VERSION_MINOR(glad_version) << std::endl;

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glEnable(GL_CULL_FACE);
        glClearColor(0.4f, 0.3f, 0.4f, 0.0f);

        //Depending on the ui, it might not be using 100% of the app size
        //Basically we need to know if the editor is occupying some space
        int viewport_width, viewport_height;
        glfwGetFramebufferSize(window, &viewport_width, &viewport_height);
        glViewport(0, 0, viewport_width, viewport_height);

        GLuint vertexarray_id;
        glGenVertexArrays(1, &vertexarray_id);
        glBindVertexArray(vertexarray_id);

        const GLfloat vertex_buffer_data[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };

        GLuint vertexbuffer_id;
        glGenBuffers(1, &vertexbuffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

        const char* vertex_shader_source = "#version 330 core\n"
                                           "layout (location = 0) in vec3 pos;\n"
                                           "void main()\n"
                                           "{\n"
                                           "gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);\n"
                                           "}\n";

        GLenum vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader_id, 1, &vertex_shader_source, nullptr);
        glCompileShader(vertex_shader_id);

        const char* fragment_shader_source = "#version 330 core\n"
                                             "out vec4 FragColor;\n"
                                             "void main()\n"
                                             "{\n"
                                             "FragColor = vec4(1.0, 0.5f, 0.2f, 1.0f);\n"
                                             "}\n";
        GLenum fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader_id, 1, &fragment_shader_source, nullptr);
        glCompileShader(fragment_shader_id);

        GLenum shader_program_id = glCreateProgram();
        glAttachShader(shader_program_id, vertex_shader_id);
        glAttachShader(shader_program_id, fragment_shader_id);
        glLinkProgram(shader_program_id);

        glDeleteShader(vertex_shader_id);
        glDeleteShader(fragment_shader_id);

        glUseProgram(shader_program_id);

        while (!glfwWindowShouldClose(window))
        {
            // processInputs(window);

            //TEST:
            double secondsSinceStartup = glfwGetTime();
            // std::cout << secondsSinceStartup << std::endl;

            // int width, height;
            // glfwGetFramebufferSize(window, &width, &height);
            // glViewport(0, 0, width, height);

            //would be nice to preserve width, height in a screen object
            // const float aspectRatio = width / (float)height;

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_id);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glDisableVertexAttribArray(0);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);

        glfwTerminate();

        return 0;
    }
}; //namespace mailman
