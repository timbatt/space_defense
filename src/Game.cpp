#include "AudioLoader.hpp"
#include "TextureLoader.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>


// Initialize static game variables
const char* Game::NAME = "Tower Defense";
int Game::WINDOW_H = 800;
int Game::WINDOW_W = 1200;
int Game::FRAME_RATE = 60;

int Game::MAX_ENTITY_PER_TYPE = 128;
int Game::MAX_PARTICLE_COUNT = 1024;

float Game::timeDelta;


sf::Clock Game::clock;
sf::RenderWindow Game::window(sf::VideoMode(Game::WINDOW_W, Game::WINDOW_H), Game::NAME);


void Game::init() {
    Game::window.setFramerateLimit(Game::FRAME_RATE);
    Game::resetTimeDelta();
    AudioLoader::load();
    TextureLoader::loadTextures();
}

void Game::resetTimeDelta() {
    Game::timeDelta = Game::clock.restart().asSeconds();
}

void Game::update() {
    Game::window.display();
    Game::window.clear();
    Game::resetTimeDelta();
}
