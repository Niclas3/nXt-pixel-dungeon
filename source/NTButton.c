#include "NTTools.h"
#include "NTDebug.h"
#include "NTButton.h"
#include <stdlib.h>

NTButton *initButtonWith(Texture2D skin,
                         Rectangle rect,
                         Sound fx_effect,
                         Font font,
                         char *title)
{
    /* NTButton *button = MemAlloc( sizeof(NTButton) ); */
    NTButton *_self = MemAlloc(sizeof(NTButton));
    Action_State inner_state = {
        .fx_state = STOP, .preview_state_count = 0, .button_state = NORMAL};
    _self->skin = skin;
    _self->rect = rect;
    _self->sound_effect = fx_effect;
    _self->title = title;
    _self->draw = draw;
    _self->__action_state = inner_state;
    _self->font = font;
    return _self;
}

void destory() {}

void _draw_skin(Texture2D chrome,
                float rate,
                Vector2 pick_position,
                Rectangle dest_rect)
{
    float x_zero_point = pick_position.x;
    float y_zero_point = pick_position.y;
    float dest_x_zero_point = dest_rect.x;
    float dest_y_zero_point = dest_rect.y;

    float dest_width = dest_rect.width;
    float dest_height = dest_rect.height;

    Rectangle window = {.x = x_zero_point,  // x
                        .y = y_zero_point,  // y
                        .width = 3,             // width
                        .height = 3};            // height

    Rectangle but_dest = {dest_x_zero_point, dest_y_zero_point,
                          window.width * rate, window.height * rate};
    Vector2 allwh= {0};

    // Top-left
    window.x = x_zero_point;
    window.y = y_zero_point;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;
    NTDrawTexture(chrome, window, but_dest);
    // Top
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.x += 3;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;

    but_dest.x += window.width * rate;

    but_dest.width = dest_width * rate;
    but_dest.height = window.height * rate;


    allwh.x += but_dest.width;
    allwh.y += but_dest.height;
    NTDrawTexture(chrome, window, but_dest);
    // top-right
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.x += 6;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;
    but_dest.x += (window.width + dest_width) * rate;
    but_dest.width = window.width * rate;
    but_dest.height = window.height * rate;

    NTDrawTexture(chrome, window, but_dest);

    // mid-left
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 3;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;
    but_dest.y += window.height * rate;

    but_dest.width = window.width * rate;
    but_dest.height = dest_height * rate;

    NTDrawTexture(chrome, window, but_dest);
    // centre
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 3;
    window.x += 3;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;
    but_dest.x += window.width * rate;
    but_dest.y += window.height * rate;

    but_dest.width = dest_width * rate;
    but_dest.height = dest_height * rate;

    NTDrawTexture(chrome, window, but_dest);

    // mid-right
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 3;
    window.x += 6;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;

    but_dest.x += (window.width + dest_width) * rate;
    but_dest.y += window.height * rate;

    but_dest.width = window.width * rate;
    but_dest.height = dest_height * rate;

    NTDrawTexture(chrome, window, but_dest);

    // bottom-left
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 6;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;

    but_dest.y += (window.height + dest_height) * rate ;
    but_dest.width = window.width * rate;
    but_dest.height = window.height * rate;

    NTDrawTexture(chrome, window, but_dest);
    /* // bottom */
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 6;
    window.x += 3;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;
    but_dest.x += window.width * rate;
    but_dest.y += (window.height + dest_height) * rate;

    but_dest.height = window.height * rate;
    but_dest.width = (window.width + dest_width) * rate;

    NTDrawTexture(chrome, window, but_dest);

    // bottom-right
    window.x = x_zero_point;
    window.y = y_zero_point;
    window.y += 6;
    window.x += 6;

    but_dest.x = dest_x_zero_point;
    but_dest.y = dest_y_zero_point;

    but_dest.x += (window.width  + dest_width) * rate;
    but_dest.y += (window.height + dest_height) * rate;

    but_dest.height = window.height * rate;
    but_dest.width = window.width * rate;

    NTDrawTexture(chrome, window, but_dest);

    float width = window.width * rate + dest_width * rate + window.width * rate;
    float height = window.height * rate +dest_height + window.height * rate ;
    allwh.x = width;
    allwh.y = height;
}

void draw(NTButton *_self)
{
    HidTouchScreenState touch_state = {0};
    Vector2 touchPoint = {0.0f, 0.0f};
    int scale_rate = 4;  // rate of skin

    hidGetTouchScreenStates(&touch_state, 1);
    // Only load the newset touch point
    if (touch_state.count != 0) {
        touchPoint.x = touch_state.touches[touch_state.count - 1].x;
        touchPoint.y = touch_state.touches[touch_state.count - 1].y;
    }

    Rectangle touch_rect = {.width = (_self->rect.width + 3 * 2) * scale_rate,
                      .height = (_self->rect.height + 3 * 2) * scale_rate,
                      .x = _self->rect.x,
                      .y = _self->rect.y};

    // Action
    if (CheckCollisionPointRec(touchPoint, touch_rect)) {
        /* if (CheckCollisionPointRec(touchPoint, rect)) { */
        // TODO: Any desired action
        // Execute when released
        DrawLine(touchPoint.x, 0, touchPoint.x, 1000, GREEN);
        NTEvent event = {
            .message = (char *) TextFormat("my name is %s", _self->title)};
        NTEvent *event_ptr = &event;
        if (_self->action) {
            _self->action(event_ptr);
        } else {
            DrawText("this button do not have action", 400, 420, 54, RED);
        }

        _self->__action_state.button_state = TOUCHED;

        if (_self->__action_state.fx_state == STOP) {
            PlaySound(_self->sound_effect);
            _self->__action_state.fx_state = PLAY;
        } else {
            // state is played
        }

    } else {
        // Release after touch
        // Touched but not in range of actived area
        Button_State button_state = _self->__action_state.button_state;

        if ((button_state == TOUCHED) && touch_state.count == 1) {
            // TODO: Any desired action
            // Still execute will released out of button range
            _self->__action_state.button_state = BS_OUT_OF_RANGE;
        } else if (button_state == TOUCHED && touch_state.count == 0) {
            // when Touch then release
            if (_self->action_when_release) {
                DrawText("release after touch", 400, 420, 54, BLACK);
            }
        } else if (button_state == BS_OUT_OF_RANGE) {
            if (touch_state.count == 0)
                // when Touch then move out of range then release
                DrawText("show after release out of button range", 400, 420, 54,
                         BLACK);
        } else {
            // In state == NORMAL / RELEASE / HIGHLIHGT
        }

        _self->__action_state.button_state = RELEASE;
        _self->__action_state.fx_state = STOP;
    }

    Vector2 title_rect =
        NTGetTextWidth(_self->font, _self->font.baseSize / 2, _self->title);

    Vector2 pick_pos = {20.0, 0.0}; // normal button pick position

    _draw_skin(_self->skin, scale_rate, pick_pos, _self->rect);

    // TODO: show icons
    /* NTDrawTexture(chrome, */
    /*         (Rectangle){20,0,9,9}, */
    /*         (Rectangle){_self->rect.x, */
    /*                     _self->rect.y, */
    /*                     90, //width */
    /*                     90}); //height */

    /* DrawTextureRec(_self->skin, _self->rect, */
    /*                (Vector2){_self->rect.x, _self->rect.y}, WHITE); */

    // show title

    int title_x = _self->rect.x + touch_rect.width /2;
    int title_y = _self->rect.y + touch_rect.height /2;

    DrawTextEx( _self->font, _self->title,
        (Vector2){title_x - (title_rect.x / 2),
                  title_y -(title_rect.y / 2)},
        _self->font.baseSize / 2, 1, PURPLE);

}
