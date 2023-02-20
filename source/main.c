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

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <switch.h>

#define FRAMES_COUNT 10
#define BAT_FRAMES_COUNT 3

// from left to right
void BreakDown2Images(Image src_image, Image *frames, int count,
                      Rectangle src_rect) {
  for (int i = 0; i <= count; i++) {
    frames[i] = GenImageColor(src_rect.width, src_rect.height, BLANK);
    ImageDraw(
        &frames[i], src_image,
        (Rectangle){i * src_rect.width, 0, src_rect.width, src_rect.height},
        (Rectangle){0, 0, src_rect.width, src_rect.height}, WHITE);
    ImageResize(&frames[i], 200, 200);
  }
}

int main(void) {
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

  InitWindow(screenWidth, screenHeight, "pixel dungeon");

  InitAudioDevice();
  SetTargetFPS(20);
  SetRandomSeed(1);
  SetTraceLogLevel(LOG_WARNING);

  // NOTE: Textures MUST be loaded after Window initialization (OpenGL context
  // is required)
  /* Texture2D texture = */
  /*     LoadTexture("romfs:/resources/raylib_logo.png"); // Texture loading */
  /* Music bgm = LoadMusicStream("romfs:/resources/background.ogg"); */
  Image avator = LoadImage("romfs:/assets/sprites/bee.png");
  Image avator_bat = LoadImage("romfs:/assets/sprites/bat.png");

  int rate = 1;
  Image frames[FRAMES_COUNT + 1];
  Image bat_frames[BAT_FRAMES_COUNT + 1];
  /* ImageResizeNN(&avator, avator.width * rate, avator.height * rate); */

  /* for (int i = 0; i <= FRAMES_COUNT; i++) { */
  /*   frames[i] = GenImageColor(16, 16, BLANK); */
  /*   ImageDraw(&frames[i], avator, (Rectangle){i * 16, 0, 16, 16}, */
  /*             (Rectangle){0, 0, 16, 16}, WHITE); */
  /*   ImageResize(&frames[i], 200, 200); */
  /* } */
  BreakDown2Images(avator, frames, FRAMES_COUNT, (Rectangle){0, 0, 16, 16});
  BreakDown2Images(avator_bat, bat_frames, BAT_FRAMES_COUNT,
                   (Rectangle){0, 0, 15, 15});

  UnloadImage(avator);
  UnloadImage(avator_bat);

  Music bgm = LoadMusicStream("romfs:/resources/bgm.mp3");
  bgm.looping = true;
  PlayMusicStream(bgm);
  Image img = GenImageColor(screenWidth, screenHeight, BLANK);
  int x = 0;
  int y = 0;
  int hue = 0;
  int fps_count = 0;
  int step = 0;
  int bat_step = 0;

  //---------------------------------------------------------------------------------------
  const char message[128] =
      "This sample illustrates a text writing\nanimation effect! Check it out!";
  int frameCount = 0;

  Rectangle des_rec = (Rectangle){0, 0, 16, 16}; // dest
  Vector2 origin = (Vector2){0.0f, 0.0f};       // poistion on source

  NPatchInfo ninfo = {(Rectangle){0, 0, 15, 16}, // what you want to get
                      0,                         // left
                      0,                         // top
                      0,                         // right
                      0,                         // bottom
                      NPATCH_NINE_PATCH};
  s32 prev_touchcount = 0;

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------
    padUpdate(&pad);
    u64 kDown = padGetButtonsDown(&pad);
    if (kDown & HidNpadButton_Plus) {
      break;
    } else if (kDown & HidNpadButton_A) {
      frameCount = 0;
    } else if (kDown & HidNpadButton_Y) {
      frameCount += 8;
    } else {
      frameCount++;
    }
    

    HidTouchScreenState state = {0};

    HidAnalogStickState analog_stick_l = padGetStickPos(&pad, 0);
    HidAnalogStickState analog_stick_r = padGetStickPos(&pad, 1);

    UpdateMusicStream(bgm);

    /* Texture texture = LoadTextureFromImage(img); */
    Texture2D test_texture = LoadTexture("romfs:/assets/sprites/bat.png");
    int rate = 10;
    /* if (test_rec.width > 32) { */
    /*   test_rec.width = 16; */
    /*   test_rec.height = 16; */
    /* } */
    hidGetTouchScreenStates(&state, 1);
    rate *= state.count;
    if(rate == 0) rate = 1;
    des_rec.width = 16 * rate;
    des_rec.height = 16 * rate;

    /* if (bat_step > 4){ */
    /*     ninfo.source.x = 0; */
    /*     bat_step= 0; */
    /* } */
    /* ninfo.source.x += 16; */
    /* bat_step++; */

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(WHITE);

    if (hidGetTouchScreenStates(&state, 1)) {
      if (state.count != prev_touchcount) {
        prev_touchcount = state.count;
        consoleClear();
      }
      for (s32 i = 0; i < state.count; i++) {
        DrawCircle(state.touches[i].x, state.touches[i].y, 100.0f, RED);
        DrawText(
            TextFormat("[%d] x=%03d, y=%03d, diameter_x=%03d, diameter_y=%03d, "
                       "rotation_angle=%03d\n",
                       i, state.touches[i].x, state.touches[i].y,
                       state.touches[i].diameter_x, state.touches[i].diameter_y,
                       state.touches[i].rotation_angle),
            40, 600, 20, BLACK);
      }
    }

    DrawText(TextSubtext(message, 0, frameCount / 10), 210, 160, 20, BLACK);
    /* DrawText(TextFormat("step %d", step), 360, 370, 50, BLACK); */
    DrawText(TextFormat("3;1H%04d; %04d", analog_stick_l.x, analog_stick_l.y),
             360, 370, 50, BLACK);
    DrawText(TextFormat("3;1H%04d; %04d", analog_stick_r.x, analog_stick_r.y),
             360, 420, 50, BLACK);
    /* DrawTexture(bee, 400, 400, WHITE); */
    /* DrawTexture(bat, 500, 500, WHITE); */
    /* DrawTexture(test_texture, 500, 550, WHITE); */

    /* DrawTextureRec(test_texture,test_rec, (Vector2){500, 549}, WHITE); */

    DrawTextureNPatch(test_texture, ninfo, des_rec, origin, 0.0f, WHITE);
    /* ninfo.source.x += 16; */
    /* des_rec.x += des_rec.width; */
    /* DrawTextureNPatch(test_texture, ninfo, des_rec, origin, 0.0f, WHITE); */
    /* ninfo.source.x += 16; */
    /* des_rec.x += des_rec.width; */
    /* DrawTextureNPatch(test_texture, ninfo, des_rec, origin, 0.0f, WHITE); */
    /* ninfo.source.x += 16; */
    /* des_rec.x += des_rec.width; */
    /* DrawTextureNPatch(test_texture, ninfo, des_rec, origin, 0.0f, WHITE); */
    /* DrawTexture(texture, 0, 0, WHITE); */

    EndDrawing();

    /* UnloadTexture(bee); // Texture unloading */
    /* UnloadTexture(bat); // Texture unloading */
    UnloadTexture(test_texture);
    /* UnloadTexture(texture); // Texture unloading */
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------

  for (int i = 0; i <= FRAMES_COUNT; i++) {
    UnloadImage(frames[i]);
  }

  for (int i = 0; i <= BAT_FRAMES_COUNT; i++) {
    UnloadImage(bat_frames[i]);
  }

  UnloadMusicStream(bgm);
  UnloadImage(img);
  CloseWindow(); // Close window and OpenGL context

  CloseAudioDevice();
  romfsExit(); // Close romfs
  //--------------------------------------------------------------------------------------

  return 0;
}
