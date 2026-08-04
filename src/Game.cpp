#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Game.hpp"
#include "AudioLoader.hpp"
#include "TextureLoader.hpp"



// Setup Settings
const char* Settings::NAME = "Tower Defense";
const int Settings::WINDOW_H = 800;
const int Settings::WINDOW_W = 1200;
const int Settings::FRAME_RATE = 60;
const int Settings::MAX_ENTITY_PER_TYPE = 128;
const int Settings::MAX_PARTICLE_COUNT = 1024;


// Initialize static game variables
float Game::timeDelta;
sf::Clock Game::clock;
sf::RenderWindow Game::window(sf::VideoMode(Settings::WINDOW_W, Settings::WINDOW_H), Settings::NAME);

bool Game::doShowHitboxes = false;


void Game::init() {
    Game::window.setFramerateLimit(Settings::FRAME_RATE);
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

void Game::showHitboxes() {
    Game::doShowHitboxes = true;
}

void Game::hideHitboxes() {
    Game::doShowHitboxes = false;
}
