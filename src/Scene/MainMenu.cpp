#include "MainMenu.hpp"
#include "raylib.h"

MainMenu::MainMenu(Game& game) :
    c_font(game.getFont()),
    c_fontSpacing(game.getFontSpacing()),
    c_mainMenuImage(game.getMainMenuImage()),
    c_mainMenuBackgroundTexture(LoadTextureFromImage(c_mainMenuImage)){
        m_game = &game;
        if (isMouseCollidingWithStartButton()) {
            m_startButtonTextColor = c_startButtonTextColorHighlight;
        }
        if (isMouseCollidingWithExitButton()) {
            m_exitButtonTextColor = c_exitButtonTextColorHighlight;
        }
};

MainMenu::~MainMenu() {
}

void MainMenu::update() {
    DrawTexture(c_mainMenuBackgroundTexture, 0, 0, WHITE);
    DrawTextEx(c_font, c_titleText, Vector2{ .x = 500, .y = 100 }, c_buttonFontSize, c_fontSpacing, c_titleTextColor);

    DrawTextEx(c_font, c_startButtonText, c_startButtonPos, c_buttonFontSize, c_fontSpacing, m_startButtonTextColor);
    if (isMouseCollidingWithStartButton()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            DrawRectangle(0, 0, 800, 600, BLACK);
            m_game->setGameState(GameState::GAMEPLAY);
        }
    }
    DrawTextEx(c_font, c_exitButtonText, c_exitButtonPos, c_buttonFontSize, c_fontSpacing, m_exitButtonTextColor);
    if (isMouseCollidingWithExitButton()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            m_game->setGameState(GameState::EXITING);
        }
    }
}

bool MainMenu::isMouseCollidingWithStartButton() {
    return CheckCollisionPointRec(GetMousePosition(), c_startButtonBounding);
}

bool MainMenu::isMouseCollidingWithExitButton() {
    return CheckCollisionPointRec(GetMousePosition(), c_exitButtonBounding);
}