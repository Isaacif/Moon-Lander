#include "TextureManager.h"
#include <iostream>

bool TextureManager::load(const std::string id, const std::string filepath) { 
    sf::Texture* texture = new sf::Texture(); //lacking dealocation 
    if (texture->loadFromFile(filepath)) {
        myTextureMap[id] = texture; 
        return true;
    }

    return false;
}

void TextureManager::draw(const std::string id, int x, int y, int width, int height, sf::Sprite* sprite) {
    
    sprite->setTexture(*myTextureMap[id]);
    sprite->setTextureRect(sf::IntRect(x, y, width, height));


}

void TextureManager::drawFrame(const std::string id, int x, int y, int width, int height, 
     int currentRow, int currentFrame, sf::Sprite* sprite, bool rotateSp) {
    
    sprite->setTexture(*myTextureMap[id]);
    sprite->setTextureRect(sf::IntRect((width*currentFrame), (height*(currentRow-1)), width, height));
    sprite->setPosition(x, y);

     if(rotateSp) {
        sprite->setScale(-1.0f, 1.0f);
    }

}

