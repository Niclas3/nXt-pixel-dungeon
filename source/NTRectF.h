#ifndef NTRectF_H
#define NTRectF_H

#include <raylib.h>

typedef struct {
    float left;
    float top;
    float right;
    float bottom;
} NTMargin ;

//shift
Rectangle NTRectShift(Rectangle* rect, float x, float y);
//resize
Rectangle NTRectResize(Rectangle* rect, float w, float h);
//is_empty
bool NTRectIsEmpty(Rectangle rect);
//set_empty
void NTRectSetEmpty(Rectangle* rect);
//union with Rectangle
void NTRectUnionWithRect(Rectangle* rect);
//union with (float x, float y) 
void NTRectUnionWithXY(Rectangle* rect, float x, float y);
//union with Vector2
void NTRectUnionWithVector2(Rectangle* rect, Vector2* vec);
//inside with Vector2
bool NTRectIsInside(Rectangle* rect, Vector2 vec);
//shrink with float d
Rectangle NTRectShrink(Rectangle* rect, float d);
//scale with float d
Rectangle NTRectScale(Rectangle* rect, float d);

Rectangle NTRectScaleWH(Rectangle *rect, float dw, float dh);

#endif
