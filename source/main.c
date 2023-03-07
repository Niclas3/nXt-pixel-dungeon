#include <switch.h>

#include "raylib.h"

#include "NTAssets.h"
#include "NTButton.h"
#include "NTDebug.h"
#include "NTRectF.h"
#include "NTTools.h"
#include "config.h"

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;
static GameScreen current_screen = LOGO;

void start_game(NTEvent *event)
{
    current_screen = GAMEPLAY;
}

void btn2action(NTEvent *event)
{
    DrawText(TextFormat("msg:%s", event->message), 100, 220, 54, PURPLE);
}

void DrawBackground(Texture2D background, int rate)
{
    for (int i = 0; i < GetScreenWidth() / background.width; i++) {
        for (int j = 0; j < GetScreenHeight() / background.height; j++) {
            NTDrawTexture(
                background,
                (Rectangle){0.0, 0.0, background.width, background.height},
                (Rectangle){background.width * i * rate,
                            background.height * j * rate,
                            background.width * rate, background.height * rate});
        }
    }
}

void DrawForeground(Texture2D foreground, int rate)
{
    for (int i = 0; i < GetScreenWidth() / foreground.width; i++) {
        for (int j = 0; j < GetScreenHeight() / foreground.height; j++) {
            NTDrawTexture(
                foreground,
                (Rectangle){0.0, 0.0, foreground.width, foreground.height},
                (Rectangle){foreground.width * i * rate,
                            foreground.height * j * rate,
                            foreground.width * rate, foreground.height * rate});
        }
    }
}

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

    Texture2D mage = LoadTexture("romfs:/assets/sprites/mage.png");

    Font global_font =
        LoadFont(TextFormat("romfs:/assets/%s", asset_fonts.PIXELFONT));
    Music theme1 =
        LoadMusicStream(TextFormat("romfs:/assets/%s", asset_music.THEME_1));
    Texture2D chrome = LoadTexture(
        NTGetAssertPath(asset_interfaces.CHROME));  // Load button texture
    Texture2D icons = LoadTexture(TextFormat(
        "romfs:/assets/%s", asset_interfaces.ICONS));  // Load button texture

    Sound fx_click = LoadSound("romfs:/assets/sounds/click.mp3");

    Rectangle rect_start = {387, 567, 200, 68};
    Rectangle rect_setting = {687, 567, 200, 68};

    NTButton *start_btn = initButtonWith(chrome, icons, rect_start, fx_click,
                                         global_font, 30, "Start");
    NTButton *setting_btn = initButtonWith(
        chrome, icons, rect_setting, fx_click, global_font, 30, "Setting");

    start_btn->action_when_release = start_game;

    theme1.looping = true;
    PlayMusicStream(theme1);

    //---------------------------------------------------------------------------------------
    int x = 0;
    int y = 0;
    int rate = 10;
    int xstep = 12;
    int ystep = 15;

    // Count frames
    int frame_count = 0;

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // count frame to div
        frame_count++;

        padUpdate(&pad);
        u64 kDown = padGetButtonsDown(&pad);
        if (kDown & HidNpadButton_Plus) {
            break;
        }

        if (kDown & HidNpadButton_Right) {
            x += xstep;
        } else if (kDown & HidNpadButton_Down) {
            y += ystep;
        } else if (kDown & HidNpadButton_Left) {
            x -= xstep;
        } else if (kDown & HidNpadButton_Up) {
            y -= ystep;
            StopMusicStream(theme1);
        }

        if (frame_count % 10 == 0) {
            x += xstep;
        }
        if (x >= 7 * xstep) {
            x = 0;
        }

        switch (current_screen) {
        case LOGO: {
            // TODO: Update LOGO screen variables here!

            frame_count++;  // Count frames

            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            if (frame_count > 120) {
                current_screen = TITLE;
            }
        } break;
        case TITLE: {
            // TODO: Update TITLE screen variables here!

            // Press enter to change to GAMEPLAY screen
            UpdateMusicStream(theme1);
            if (kDown & HidNpadButton_A) {
                current_screen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY: {
            // TODO: Update GAMEPLAY screen variables here!


            // Press enter to change to ENDING screen
            if (kDown & HidNpadButton_A) {
                current_screen = ENDING;
            }
        } break;
        case ENDING: {
            // TODO: Update ENDING screen variables here!

            // Press enter to return to TITLE screen
            if (kDown & HidNpadButton_A) {
                current_screen = TITLE;
            }
        } break;
        default:
            break;
        }


        Texture2D background =
            LoadTexture("romfs:/assets/interfaces/arcs1.png");
        Texture2D foreground =
            LoadTexture("romfs:/assets/interfaces/arcs2.png");

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);

        switch (current_screen) {
        case LOGO: {
            // TODO: Draw LOGO screen here!
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

        } break;
        case TITLE: {
            // TODO: Draw TITLE screen here!
            DrawBackground(background, rate / 2);
            DrawForeground(foreground, rate / 2);

            start_btn->draw(start_btn);
            setting_btn->draw(setting_btn);

        } break;
        case GAMEPLAY: {
            // TODO: Draw GAMEPLAY screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
            DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
            DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220,
                     20, MAROON);
        } break;
        case ENDING: {
            // TODO: Draw ENDING screen here!
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220,
                     20, DARKBLUE);
        } break;
        default:
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
        UnloadTexture(background);
        UnloadTexture(foreground);
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    UnloadMusicStream(theme1);
    UnloadTexture(icons);
    UnloadTexture(chrome);

    UnloadFont(global_font);

    destoryButton(start_btn);
    destoryButton(setting_btn);

    CloseWindow();  // Close window and OpenGL context
    CloseAudioDevice();
    romfsExit();  // Close romfs
    //--------------------------------------------------------------------------------------
    return 0;
}
