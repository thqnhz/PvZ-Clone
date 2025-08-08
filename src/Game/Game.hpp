#pragma once

#include <unistd.h>
#include "raylib.h"

class MainMenu;

enum class GameState {
    EXITING,
    LOADING,
    MAIN_MENU,
    GAMEPLAY
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

    MainMenu* m_mainMenu;
public:
    Game();
    ~Game();
    void run();
    void update();
    void render();
    Font getFont();
    int getFontSpacing();
    Image getMainMenuImage();
    void setGameState(GameState gs);
};