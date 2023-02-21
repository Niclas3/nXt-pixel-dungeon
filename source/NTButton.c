#include "NTButton.h"
#include <stdlib.h>


NTButton *initButtonWith(Texture2D skin,
                         Rectangle rect,
                         Rectangle bounds,
                         Sound fx_effect,
                         char *title)
{
    /* NTButton *button = MemAlloc( sizeof(NTButton) ); */
    NTButton *_self = MemAlloc(sizeof(NTButton));
    Action_State inner_state = {
        .fx_state = STOP, .preview_state_count = 0, .button_state = NORMAL};
    _self->skin = skin;
    _self->rect = rect;
    _self->bounds = bounds;
    _self->sound_effect = fx_effect;
    _self->title = title;
    _self->draw = draw;
    _self->__action_state = inner_state;
    return _self;
}

void destory() {}

void draw(NTButton *_self)
{
    float frameHeight = (float) _self->skin.height / 3;

    HidTouchScreenState touch_state = {0};
    Vector2 touchPoint = {0.0f, 0.0f};

    hidGetTouchScreenStates(&touch_state, 1);
    if (touch_state.count != 0) {
        touchPoint.x = touch_state.touches[touch_state.count - 1].x;
        touchPoint.y = touch_state.touches[touch_state.count - 1].y;
    }

    // Check button state
    if (CheckCollisionPointRec(touchPoint, _self->bounds)) {
        // execute will touched
        // TODO: Any desired action
        // execute will released
        /* if (_self->__action_state.button_state != TOUCHED) { */
            DrawText("show when touch", 400, 420, 54, RED);
            _self->__action_state.button_state = TOUCHED;
        /* } */

        if (_self->__action_state.fx_state == STOP) {
            PlaySound(_self->sound_effect);
            _self->__action_state.fx_state = PLAY;
        }
        // release some touch point
        if (touch_state.count < _self->__action_state.preview_state_count) {
            _self->__action_state.fx_state = STOP;
            _self->__action_state.preview_state_count = touch_state.count;
            _self->__action_state.button_state = RELEASE;
        }
    } else {
        // release some touch point
        if (_self->__action_state.button_state == TOUCHED &&
            (touch_state.count < _self->__action_state.preview_state_count ||
             touch_state.count == 0)) {
            _self->__action_state.button_state = RELEASE;
            _self->__action_state.fx_state = STOP;
            _self->__action_state.preview_state_count = touch_state.count;

            // TODO: Any desired action
            // execute will released
            DrawText("show after release", 400, 420, 54, BLACK);
        }
    }

    /* Calculate button frame rectangle to draw depending on button state */
    _self->rect.y = _self->__action_state.button_state * frameHeight;

    DrawTextureRec(_self->skin, _self->rect,
                   (Vector2){_self->bounds.x, _self->bounds.y}, WHITE);
}
