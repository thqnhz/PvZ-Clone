#include "../Scene/Loading.hpp"
#include "../Game/Game.hpp"
#include "raylib.h"

LoadingScreen::LoadingScreen(Game& game) :
    c_mainMenuBackgroundTexture(LoadTextureFromImage(game.getMainMenuImage())) {
        m_game = &game;
}

LoadingScreen::~LoadingScreen() {
}

void LoadingScreen::update() {
    render();
    m_game->setGameState(GameState::MAIN_MENU);
}

void LoadingScreen::render() {
    DrawTexture(c_mainMenuBackgroundTexture, 0, 0, WHITE);
}