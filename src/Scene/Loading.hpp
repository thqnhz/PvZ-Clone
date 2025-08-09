#pragma once

#include "raylib.h"

class Game;

class LoadingScreen {
    const Texture2D c_mainMenuBackgroundTexture;
    Game* m_game;
public:
    LoadingScreen(Game& game);
    ~LoadingScreen();
    void update();
    void render();
};