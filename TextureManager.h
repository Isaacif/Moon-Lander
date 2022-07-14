#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager 
{
    public:
        bool load(const std::string id, const std::string filepath);
        void draw(const std::string id, int x, int y, int width, int height, sf::Sprite* sprite);
        void drawFrame(const std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,  sf::Sprite* sprite, bool rotateSp);

    
    private:
        std::map<std::string, sf::Texture*> myTextureMap;

};  