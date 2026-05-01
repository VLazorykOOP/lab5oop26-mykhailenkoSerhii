#include "Task3.h"

#include <iosfwd>
#include <iostream>

class Window
{
    protected:
    int width;
    int height;

    public:
    Window(int w, int h)
    {
        width = w;
        height = h;
    }

    Window(const Window& other)
    {
        width = other.width;
        height = other.height;
    }

    Window& operator=(const Window& other)
    {
        width = other.width;
        height = other.height;

        return *this;
    }

    Window(Window& other) noexcept
    {
        width = other.width;
        height = other.height;

        other.width = 0;
        other.height = 0;
    }

    Window& operator=(Window&& other) noexcept
    {
        width = other.width;
        height = other.height;

        other.width = 0;
        other.height = 0;

        return *this;
    }

    friend std::istream& operator>>(std::istream& is, Window& w)
    {
        std::cout << "Input width and height: " << std::endl;
        is >> w.width;
        is >> w.height;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, Window& w)
    {
        os << "Width : " << w.width << std::endl;
        os << "Height : " << w.height << std::endl;
        return os;
    }
};

class TitledWindow : public Window
{
    std::string title;

public:
    TitledWindow(int w, int h, const std::string& name) : Window(w, h)
    {
        title = name;
    }

    TitledWindow(const TitledWindow& other) : Window(other)
    {
        title = other.title;
    }

    TitledWindow& operator=(const TitledWindow& other)
    {
        Window::operator=(other);
        title = other.title;

        return *this;
    }

    TitledWindow(TitledWindow&& other) noexcept : Window(other)
    {
        title = other.title;
        other.title = "";
    }

    TitledWindow& operator=(TitledWindow&& other) noexcept
    {
        Window::operator=(other);
        title = other.title;
        other.title = "";

        return *this;
    }

    friend std::istream& operator>>(std::istream& is, TitledWindow& window)
    {
        is >> static_cast<Window&>(window);
        is >> window.title;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, TitledWindow& window)
    {
        os << static_cast<Window&>(window);
        os << window.title;

        return os;
    }
};

void task3()
{
    Window w1 = Window(1080, 960);
    std::cout << w1 << std::endl;

    TitledWindow w2 = TitledWindow(1080, 960, "OOP");
    std::cout << w2 << std::endl;

    Window w3 = Window(16, 9);
    std::cout << w3 << std::endl;

    std::cout << "w1 = w3" << std::endl;
    w1 = w3;
    std::cout << (w1) << std::endl;
}
