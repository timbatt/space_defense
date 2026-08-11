#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Game.hpp"
#include "AudioLoader.hpp"
#include "TextureLoader.hpp"
#include "shorthand.hpp"



// Initialize static game variables
float Game::timeDelta;
sf::Clock Game::clock;
bool Game::doShowHitboxes = false;

// Window settings
sf::FloatRect Game::windowViewRect;
sf::RenderWindow Game::window(sf::VideoMode(Settings::WINDOW_W, Settings::WINDOW_H), Settings::NAME);

void Game::init() {
    AudioLoader::load();
    TextureLoader::loadTextures();
    
    Game::windowViewRect = sf::FloatRect(0, 0, Settings::WINDOW_W, Settings::WINDOW_H);
    Game::window.setFramerateLimit(Settings::FRAME_RATE);
    Game::window.setSize(Vec2u(Settings::WINDOW_W, Settings::WINDOW_H));
    Game::window.setView(sf::View(Game::windowViewRect));
    Game::window.setTitle(Settings::NAME);
    
    
    Game::resetTimeDelta();
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
