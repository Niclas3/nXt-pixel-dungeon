#ifndef NTTOOLS_H
#define NTTOOLS_H

#include <raylib.h>


Vector2 NTGetTextWidth(Font used_font, int font_size, char *text);
Vector2 NTGetRectPostion(Rectangle rect);
Vector2 NTGetRectWidthandHeight(Rectangle rect);
void NTDrawTexture(Texture2D texture, Rectangle pick_window, Rectangle dest);
int NTGetRandomValue(int min, int max); // include both

#endif
