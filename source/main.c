/*******************************************************************************************
 *
 *   raylib [textures] example - Texture loading and drawing
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2014 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <switch.h>
#include "NTButton.h"
#include "raylib.h"

#define FPS 60

int main(void)
{
    // Init the gamepad for reading all controllers
    PadState pad;
    padInitializeAny(&pad);
    hidInitializeTouchScreen();

    // Init romfs if needed
    romfsInit();

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "nXt pixel dungeon");

    InitAudioDevice();
    SetTargetFPS(FPS);
    SetTraceLogLevel(LOG_WARNING);

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context
    // is required)

    Music bgm = LoadMusicStream("romfs:/resources/background.ogg");
    Sound fx_click = LoadSound("romfs:/assets/sounds/click.mp3");

    Texture2D button =
        LoadTexture("romfs:/resources/button.png");  // Load button texture

    float frameHeight = (float) button.height / NUM_FRAMES;
    Rectangle sourceRec = {0, 0, (float) button.width, frameHeight};
    Rectangle btn2Bounds = {600, 500, button.width, frameHeight};

    NTButton *btn = initButtonWith(button, sourceRec, btn2Bounds, fx_click,
                                   "3 test action like class");

    bgm.looping = true;
    PlayMusicStream(bgm);

    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        padUpdate(&pad);
        u64 kDown = padGetButtonsDown(&pad);
        if (kDown & HidNpadButton_Plus) {
            break;
        }

        UpdateMusicStream(bgm);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        btn->draw(btn);

        EndDrawing();

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadMusicStream(bgm);
    UnloadTexture(button);
    CloseWindow();  // Close window and OpenGL context

    CloseAudioDevice();
    romfsExit();  // Close romfs
    //--------------------------------------------------------------------------------------

    return 0;
}
