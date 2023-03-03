#include "NTRectF.h"

// shift
Rectangle NTRectShift(Rectangle *rect, float x, float y)
{
    return (Rectangle){rect->x + x, rect->y + y, rect->width, rect->height};
}
// resize
Rectangle NTRectResize(Rectangle *rect, float w, float h)
{
    return (Rectangle){rect->x, rect->y, rect->width + w, rect->height + h};
}
// is_empty
bool NTRectIsEmpty(Rectangle rect)
{
    return !rect.width || !rect.height;
}
// set_empty
void NTRectSetEmpty(Rectangle *rect)
{
    rect->height = 0;
    rect->width = 0;
}
// union with Rectangle
void NTRectUnionWithRect(Rectangle *rect) {}
// union with (float x, float y)
void NTRectUnionWithXY(Rectangle *rect, float x, float y);
// union with Vector2
void NTRectUnionWithVector2(Rectangle *rect, Vector2 *vec);
// inside with Vector2
bool NTRectIsInside(Rectangle *rect, Vector2 vec){
    return false;
}
// shrink with float d
Rectangle NTRectShrink(Rectangle *rect, float d)
{
    return (Rectangle){0};
}
// scale with float d
Rectangle NTRectScale(Rectangle *rect, float d)
{
    return (Rectangle){.x = rect->x,
                       .y = rect->y,
                       .width = rect->width * d,
                       .height = rect->height * d};
}

Rectangle NTRectScaleWH(Rectangle *rect, float dw, float dh)
{
    return (Rectangle){.x = rect->x,
                       .y = rect->y,
                       .width = rect->width * dw,
                       .height = rect->height * dh};
}
