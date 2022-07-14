#include "Game.h"
#include <iostream>
#include <vector>
#include <tuple>

int x = 950, y = 150;
float vt = 0.25f, ht = y, mt = 10.f;
Game::Game(): myWindow("GameShow", sf::Vector2u(1920, 1080)) { //Passing Window arguments construtor to Game constructor
    
    CountTime();
    srand(time(NULL));

    if(myTextureManager.load("back", "assets/thumb.jpg")) {
     
        std::cout << "Load Sucess back\n";
    }

    myTextureManager.draw("back", 0, 0, 1920, 1080, &backspr);
    
    
    if(myTextureManager.load("ship", "assets/download.png")) {
     
        std::cout << "Load Sucess ship\n";
    }


    std::cout <<  __cplusplus;
    myTextureManager.drawFrame("ship", 950, 150, 121, 250, 1, mycurrentFrameF, &ship, false);


    //myTextureManager.drawFrame("Char1", 65, 100, 162, 162, 1, mycurrentFrame, &FantasyWarrior, false); 
    //myTextureManager.drawFrame("Char2", 165, 100, 162, 162, 1, mycurrentFrame, &HunterWarrior, true); 

   /* if((FantasyWarrior).getTexture() == nullptr) {

        std::cout << "Draw Fantasy Failed\n";
    }

    if((HunterWarrior).getTexture() == nullptr) {

        std::cout << "Draw Hunter Failed\n";
    }

    */


}

Game::~Game(){}

sf::Time Game::GetElapsed(){ return mySTimer; }
Window* Game::GetWindow(){ return &myWindow; }

void Game::CountTimePh()  {
     myPhysicsTimer += myPhysicsclock.restart();
     if(myPhysicsTimer.asSeconds() >= frametime) { 
        myPhysicsTimer -= sf::seconds(frametime);
     } 
}

void Game::CountTime() {
    mySTimer = mySclock.getElapsedTime();
}

void Game::HandleInput() {
	// Input handling.
}

void Game::Update() {
    
    using namespace std;

    myWindow.Update();
    mycurrentFrameF = (int)((mySclock.getElapsedTime().asMilliseconds()/150) % 10);
    mycurrentFrameH = (int)((mySclock.getElapsedTime().asMilliseconds()/150) % 8);
    float vt1, ht1, mt1;
    tie(vt1, ht1, mt1) = solver(&ht, &vt, &mt, 0.001f, 0.0125f, 0.0015f);
    vt = vt1; ht = ht1; mt=mt1;

    if(ship.getPosition().y < 795) {
        
        ship.setPosition(x, ht1);
    
    }
}


std::tuple<float, float, float> Game::solver(float* h0, float* v0, float* m0, float k, float alpha, float g = 1.62f) {

    //std::vector<float> m_t = {m0}, h_t = {h0}, v_t = {v0};
    float v_t = -g + (alpha/(*m0)); float m_t = -k*alpha;
    float vt = *v0 + v_t*mySclock.getElapsedTime().asMilliseconds()/250;
    float ht = *h0 - vt*mySclock.getElapsedTime().asMilliseconds()/250;
    float mt = *m0 + m_t*mySclock.getElapsedTime().asMilliseconds()/250;



    return std::make_tuple(vt, ht, mt);

}

void Game::Render() {
	myWindow.BeginDraw(); // Clear.
	myWindow.Draw(backspr);
    myWindow.Draw(ship);
	myWindow.EndDraw(); // Display.
}