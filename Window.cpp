#include "Window.h"

Window::Window(const std::string& title, const sf::Vector2u& size) {
    
    Setup(title, size);

}

Window::~Window() {
    
    Destroy();

}

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
    
    mywindowTitle = title;
    myWindowSize = size;
    isfullscreen = false;
    isdone = false;
    Create();

}

void Window::Create() {

    auto style = (isfullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    myWindow.create({myWindowSize.x, myWindowSize.y, 32}, mywindowTitle, style);

}

void Window::Destroy() {
 
    myWindow.close();

}

void Window::Update() {

    sf::Event event;
    while(myWindow.pollEvent(event)) {

        if(event.type == sf::Event::Closed) 
        {
            isdone = true;
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) 
        {
            ToggleFullscreen();
        }

    }

}

void Window::ToggleFullscreen() {

    isfullscreen = !isfullscreen;
    Destroy();
    Create();

}

void Window::BeginDraw() {
    
    myWindow.clear(sf::Color::Black);

}

void Window::EndDraw() {

    myWindow.display();

}

void Window::Draw(sf::Drawable& drawable) {

    myWindow.draw(drawable);

}

bool Window::IsDone() { return isdone; }
bool Window::IsFullScreen() { return isfullscreen; }

sf::Vector2u Window::GetWindowSize() { return myWindowSize; }



