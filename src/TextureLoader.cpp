#include "TextureLoader.hpp"


sf::Texture TextureLoader::particleTexture;
sf::Texture TextureLoader::enemyTexture;
sf::Texture TextureLoader::ShipTexture;
sf::Texture TextureLoader::nullTexture;

void TextureLoader::loadTextures() {
    TextureLoader::particleTexture.loadFromFile("resources/particle.png");
    TextureLoader::ShipTexture.loadFromFile("resources/turret.png");
    TextureLoader::enemyTexture.loadFromFile("resources/ufo.png");
}