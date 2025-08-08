#include "Game.hpp"
#include "../Scene/MainMenu.hpp"
#include "raylib.h"

Game::Game() {
    InitWindow(c_screenWidth, c_screenHeight, c_title);
    SetWindowIcon(c_iconImage);
    
    m_mainMenuBackgroundTexture = LoadTextureFromImage(c_mainMenuImage);
    m_font = LoadFontEx(TextFormat("%s/assets/creepster.ttf", c_appDir), c_loadedFontSize, 0, 0);
    SetTargetFPS(60);
    m_gameState = new GameState(GameState::LOADING);
    m_isRunning = true;
    m_mainMenu = new MainMenu(*this);
}

Game::~Game() {
    CloseWindow();
    UnloadFont(m_font);
    UnloadImage(c_iconImage);
    UnloadImage(c_mainMenuImage);
    UnloadTexture(m_mainMenuBackgroundTexture);
}

void Game::run() {
    while (m_isRunning && !WindowShouldClose()) {
        BeginDrawing();
        update();
        DrawFPS(10, 10);
        EndDrawing();
    }
}

void Game::update() {
    switch (*m_gameState) {
        case GameState::LOADING:
            sleep(3);
            setGameState(GameState::MAIN_MENU);
            break;
        case GameState::EXITING:
            m_isRunning = false;
            break;
        case GameState::GAMEPLAY:
            sleep(3);
            setGameState(GameState::MAIN_MENU);
            break;
        case GameState::MAIN_MENU:
            m_mainMenu->update();
            break;
    }
}

void Game::render() {
    
}

Font Game::getFont() {
    return m_font;
}

int Game::getFontSpacing() {
    return c_fontSpacing;
}

Image Game::getMainMenuImage() {
    return c_mainMenuImage;
}

void Game::setGameState(GameState gs) {
    *m_gameState = gs;
}
