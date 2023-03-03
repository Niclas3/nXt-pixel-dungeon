#ifndef NTBUTTON_H
#define NTBUTTON_H

#include <raylib.h>
#include <switch.h>

#include "NTEvent.h"
typedef enum __Button_State { 
    BS_OUT_OF_RANGE=-1,
    NORMAL = 0,
    TOUCHED,
    HIGHLIGHT,
    RELEASE
} Button_State;

typedef enum __Sound_Effect_State {
    PLAY,
    PAUSE,
    STOP
} Fx_State;

typedef struct __Action_State {
    Fx_State fx_state;          // show if fx_effect is actived
    int preview_state_count; // store last state count of fingle touching
    Button_State  button_state;         // button state like CLICK MOVEOUT
}Action_State;

//Load resources

//Init a button 
//@skin Texture2D resource
//@icon icon of button
//@rect Rectangle rect   rect of button
//@bounds Rectangle bounds
//@sound_effectsound_effect
//@action action when press button
//@action_when_release action when release after press

typedef struct __NTButton {
    Texture2D skin;
    Texture2D icon;
    Rectangle rect;
    Sound sound_effect;
    Font font;
    char *title;
    void (*draw)(struct __NTButton *);
    void (*action)(NTEvent *event);
    void (*action_when_release)(NTEvent *event);
    Action_State __action_state; // inner state
    // SEL *action;
}NTButton;

//Init a Button
NTButton* initButtonWith(Texture2D skin,
                Rectangle rect,
                Sound fx_effect,
                Font font,
                char *title);

//TODO:
NTButton* initButton();

// Draw a button
void draw(NTButton *_self);
#endif
