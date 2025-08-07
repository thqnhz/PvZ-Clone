#pragma once

#include <unistd.h>
#include "raylib.h"

enum class GameState {
    EXITING = 0,
    LOADING = 1,
    MAIN_MENU = 2,
    GAMEPLAY = 3
};

class Game {
    const int c_screenWidth = 800;
    const int c_screenHeight = 600;
    const int c_loadedFontSize = 72;
    const int c_fontSpacing = 1;
    const char* c_title = "PLNT vs. ZMBZ";
    const char* c_workingDir = GetWorkingDirectory();
    const char* c_appDir = GetPrevDirectoryPath(c_workingDir);
    const Image c_iconImage = LoadImage(TextFormat("%s/assets/icon.png", c_appDir));
    const Image c_mainMenuImage = LoadImage(TextFormat("%s/assets/main_menu.png", c_appDir));
    
    Font m_font;
    GameState* m_gameState;
    Texture2D m_mainMenuBackgroundTexture;
    bool m_isRunning;
public:
    Game();
    ~Game();
    void run();
    void update();
    Font getFont();
    int getFontSpacing();
    Image getMainMenuImage();
    void setGameState(GameState gs);
};