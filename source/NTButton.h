#ifndef NTBUTTON_H
#define NTBUTTON_H

#include <raylib.h>
#include <switch.h>

typedef enum __Button_State { 
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
//@param1 Texture2D resource
//@param2 Rectangle rect   rect of button
//@param3 Rectangle bounds
//@param4 Callback callback
//@param5 Sound sound_effect
typedef struct __NTButton {
    Texture2D skin;
    Rectangle rect;
    Rectangle bounds;
    Sound sound_effect;
    char *title;
    void (*draw)(struct __NTButton *);
    Action_State __action_state; // inner state
    // SEL *action;
}NTButton;


//Init a Button
NTButton* initButtonWith(Texture2D skin,
                Rectangle rect,
                Rectangle bounds,
                Sound fx_effect,
                char *title);

NTButton* initButton();

// Draw a button
void draw(NTButton *_self);
#endif
