#pragma once

#include "raylib.h"
#include "../Game/Game.hpp"

class MainMenu {
    const Font c_font;
    const int c_fontSpacing;
    const Image c_mainMenuImage;
    Texture2D c_mainMenuBackgroundTexture;

    const Color c_titleTextColor = BLACK;
    const int c_buttonFontSize = 60;
    const char* c_titleText = "PLNT\n vs.\nZMBZ";
    const char* c_startButtonText = "START";
    const char* c_exitButtonText = "EXIT";
    const Vector2 c_startButtonPos = { .x = 170, .y = 200 };
    const Vector2 c_exitButtonPos = {
        .x = c_startButtonPos.x,
        .y = c_startButtonPos.y + c_buttonFontSize + 50
    };

    Color m_startButtonTextColor = BLACK;
    const Color c_startButtonTextColorHighlight = DARKGREEN;
    const Vector2 c_startButtonHitboxSize = MeasureTextEx(c_font, c_startButtonText, c_buttonFontSize, c_fontSpacing);
    const Rectangle c_startButtonBounding = {
        .x = c_startButtonPos.x,
        .y = c_startButtonPos.y,
        .width = c_startButtonHitboxSize.x,
        .height = c_startButtonHitboxSize.y
    };
    Color m_exitButtonTextColor = BLACK;
    const Color c_exitButtonTextColorHighlight = RED;
    const Vector2 c_exitButtonHitboxSize = MeasureTextEx(c_font, c_exitButtonText, c_buttonFontSize, c_fontSpacing);
    const Rectangle c_exitButtonBounding = {
        .x = c_exitButtonPos.x,
        .y = c_exitButtonPos.y,
        .width = c_exitButtonHitboxSize.x,
        .height = c_exitButtonHitboxSize.y
    };
    Game* m_game;
public:
    MainMenu(Game& game);
    ~MainMenu();
    void update();
    bool isMouseCollidingWithStartButton();
    bool isMouseCollidingWithExitButton();
};