#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Window
{
    public:

        Window(const std::string& title, const sf::Vector2u& size);
        ~Window();

        void RenderDraw();
        void BeginDraw();
        void EndDraw();
        void Draw(sf::Drawable& drawable);
        void Update();

        bool IsDone();
        bool IsFullScreen();
        
        sf::Vector2u GetWindowSize();
        void ToggleFullscreen();

    private:

        void Setup(const std::string& title, const sf::Vector2u& size);
        void Destroy();
        void Create();

        sf::RenderWindow myWindow;
        sf::Vector2u myWindowSize;
        std::string mywindowTitle;

        bool isdone;
        bool isfullscreen;
};