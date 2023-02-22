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
    // Only load the newset touch point
    if (touch_state.count != 0) {
        touchPoint.x = touch_state.touches[touch_state.count - 1].x;
        touchPoint.y = touch_state.touches[touch_state.count - 1].y;
    }

    // Check button state
    if (CheckCollisionPointRec(touchPoint, _self->bounds)) {
        // TODO: Any desired action
        // Execute when released
        NTEvent event = {
            .message = TextFormat("my name is %s", _self->title)
        };
        NTEvent *event_ptr = &event;
        if(_self->action){
            _self->action(event_ptr);
        }else{
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
            if(_self->action_when_release){
                DrawText("release after touch", 400, 420, 54, BLACK);
            }
        } else if (button_state == BS_OUT_OF_RANGE) {
            if (touch_state.count == 0)
                // when Touch then move out of range then release
                DrawText("show after release out of button range", 400, 420, 54, BLACK);
        } else {
            // In state == NORMAL / RELEASE / HIGHLIHGT
        }

        _self->__action_state.button_state = RELEASE;
        _self->__action_state.fx_state = STOP;
    }

    /* Calculate button frame rectangle to draw depending on button state */
    _self->rect.y = _self->__action_state.button_state * frameHeight;

    DrawTextureRec(_self->skin, _self->rect,
                   (Vector2){_self->bounds.x, _self->bounds.y}, WHITE);
}
