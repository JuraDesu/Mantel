//
// Created by h4d3s on 2/19/25.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GLFW/glfw3.h>

struct WinParams{
    int width;
    int height;
    const char* title;
};

inline std::ostream& operator<<(std::ostream& os, const WinParams& params){
    return os << "\tTitle: " << params.title <<"\n\tWidth: " << params.width << "\n\tHeight: " << params.height;
}

class Window{
    GLFWwindow* window;
    WinParams winParams;
    static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
    public:
    Window(const char* title, int width, int height);
    ~Window() {glfwDestroyWindow(window);}

    void PrintWinParams()const;
};
#endif //WINDOW_H
