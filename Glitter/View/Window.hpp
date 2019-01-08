#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum WinFlags {
    WIN_HIDDEN = 0x1,
    WIN_FULLSCREEN = 0x2,
    WIN_WINDOWED = 0x3,
    WIN_BORDERLESS = 0x4,
    WIN_ENABLE_VSYNC = 1,
    WIN_DISABLE_VSYNC = 0
};

class Window {
private:
    GLFWwindow* glWin;
    WinFlags winFlags;

    std::string winName;
    int screenW;
    int screenH;
    int screenX;
    int screenY;

    void SetCreateHints(unsigned int flags);

public:
    Window();
    ~Window();

    int CreateWin(std::string inWinName, int inScreenW, int inScreenH, int inScreenX, int inScreenY, unsigned int inFlags);

    void SwapBuffers();

    int getScreenW() { return screenW; }
    int getScreenH() { return screenH; }
};
