#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Game.hpp"
#include "AudioLoader.hpp"
#include "TextureLoader.hpp"
#include "shorthand.hpp"



// Initialize static game variables
float Game::timeDelta;
sf::Clock Game::clock;
sf::RenderWindow Game::window(sf::VideoMode(Settings::WINDOW_W, Settings::WINDOW_H), Settings::NAME);

bool Game::doShowHitboxes = false;


void Game::init() {
    Game::window.setFramerateLimit(Settings::FRAME_RATE);
    Game::window.setSize(Vec2u(Settings::WINDOW_W, Settings::WINDOW_H));
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
