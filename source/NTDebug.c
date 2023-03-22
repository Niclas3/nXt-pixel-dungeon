#include "NTDebug.h"
#include <switch.h>
void ShowLine(){
    Vector2 v_start = (Vector2){.x= (2.0 / 3.0) * (float)GetScreenWidth(), .y=0};
    Vector2 v_end   = (Vector2){.x= (2.0 / 3.0) * (float)GetScreenWidth(), .y=(float)GetScreenHeight()};
    DrawLineEx( v_start,v_end, 4.0, BLACK);
}

void ShowRectInfo(Rectangle rect1)
{
    DrawRectangleRec(rect1, BLUE);
    DrawText(TextFormat("x:%f y:%f w:%f h:%f", rect1.x, rect1.y, rect1.width,
                        rect1.height),
             200, 539, 20, RED);
}

void ShowVector2Info(Vector2 v)
{
    char* text =TextFormat("x:%f y:%f", v.x, v.y);
    Vector2 t_Hw = MeasureTextEx(GetFontDefault(), text, 20, 2);
    DrawRectangle(200, 560, t_Hw.x, t_Hw.y, ORANGE);
    DrawText(text, 200, 560, 20, GREEN);
}

void ShowRuler(bool is_h)
{
    HidTouchScreenState touch_state = {0};
    Vector2 touchPoint = {0.0f, 0.0f};

    hidGetTouchScreenStates(&touch_state, 1);
    // Only load the newset touch point
    if (touch_state.count != 0) {
        touchPoint.x = touch_state.touches[touch_state.count - 1].x;
        touchPoint.y = touch_state.touches[touch_state.count - 1].y;
    }
    int degree = 0;

    Rectangle rec = {
        .x = touchPoint.x, .y = touchPoint.y, .width = 600, .height = 100};

    if (is_h) {
        DrawRectanglePro(rec, (Vector2){0, 0}, degree, GREEN);
        for (int i = 0; i < rec.width / 10; i++) {
            int height = 10;
            Vector2 s_pos = {.x = rec.x + i * 10, .y = rec.y};
            Vector2 e_pos = {.x = rec.x + i * 10, .y = rec.y + height};
            if (i % 10 == 0) {
                e_pos.y += height;
                DrawLineEx(s_pos, e_pos, 1.0, BLUE);
            } else {
                DrawLineEx(s_pos, e_pos, 1.0, RED);
            }
        }
    } else {
        degree = 90;
        DrawRectanglePro(rec, (Vector2){0, 0}, degree, GREEN);
        for (int i = 0; i < rec.width / 10; i++) {
            int height = 10;
            Vector2 s_pos = {.x = rec.x + i * 10, .y = rec.y};
            Vector2 e_pos = {.x = rec.x + i * 10, .y = rec.y + height};
            if (i % 10 == 0) {
                e_pos.y += height;
                DrawLineEx(s_pos, e_pos, 1.0, BLUE);
            } else {
                DrawLineEx(s_pos, e_pos, 1.0, RED);
            }
        }
    }
}

void ShowStr(char* text)
{
    Vector2 t_Hw = MeasureTextEx(GetFontDefault(), text, 20, 2);
    DrawRectangle(200, 560, t_Hw.x, t_Hw.y, ORANGE);
    DrawText(text, 200, 560, 20, GREEN);
}

