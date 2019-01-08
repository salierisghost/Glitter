#include "Window.hpp"

Window::Window() {}

Window::~Window() {}

int Window::CreateWin(std::string inWinName, int inScreenW, int inScreenH, int inScreenX, int inScreenY, unsigned int inFlags) {

    winName = inWinName;
    screenW = inScreenW;
    screenH = inScreenH;

    // int flags = SDL_WINDOW_OPENGL;
    // bool vSync = 0;

    // //Apends SDL flags for the window.
    // if (inFlags & WIN_HIDDEN)
    //     flags |= SDL_WINDOW_HIDDEN;
    // if (inFlags & WIN_BORDERLESS)
    //     flags |= SDL_WINDOW_BORDERLESS;
    // if (inFlags & WIN_WINDOWED)
    //     flags |= SDL_WINDOW_SHOWN;
    // if (inFlags & WIN_FULLSCREEN)
    //     flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    // if (inFlags & WIN_ENABLE_VSYNC)
    //     vSync = 1;
    // if (inFlags & WIN_DISABLE_VSYNC)
    //     vSync = 0;


    //Sets double buffering... kind of obvious.
    // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // //Creates SDL Window.
    // sdlWin = SDL_CreateWindow(winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, flags);
    // if (sdlWin == nullptr)
    //     fatalError("ERROR: SDL Window could not be opened.");

    // //Sets up the OpenGL Context.
    // SDL_GLContext glContext = SDL_GL_CreateContext(sdlWin);
    // if (glContext == nullptr)
    //     fatalError("SDL GL Context could not be created.");

    // //Sets up glew
    // GLenum glEnum = glewInit();
    // //Add more error checking here for glEnum.
    // if (glEnum != GLEW_OK)
    //     fatalError("Glew Init did not init.");

    // //Clears the screen.
    // glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    // std::printf("*** OpenGL Version: %s ***\n", glGetString(GL_VERSION));

    // //Sets VSync
    // SDL_GL_SetSwapInterval(vSync);

    // // Enable Alpha Blending.
    // glEnable(GL_BLEND);
    // //How to do the alpha blending.
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // return 0;

    winName = inWinName;
    screenW = inScreenW;
    screenH = inScreenH;
    screenX = inScreenX;
    screenY = inScreenY;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glWin = glfwCreateWindow(screenW, screenH, winName.c_str(), nullptr, nullptr);

    if (glWin == nullptr) {
        fprintf(stderr, "Failed to create OpenGL Context");
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(glWin);
    gladLoadGL();
    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
}

void Window::SetCreateHints(unsigned int flags) {
    if (flags & WIN_HIDDEN) 
        glfwHideWindow(glWin);
//    if (flags & WIN_FULLSCREEN)
//        glfw
}

void Window::SwapBuffers() {
    glfwSwapBuffers(glWin);
}
