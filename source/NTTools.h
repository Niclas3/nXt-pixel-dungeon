#ifndef NTTOOLS_H
#define NTTOOLS_H

#include <raylib.h>

Vector2 NTGetTextWidth(Font used_font, int font_size, char *text);
void NTDrawTexture(Texture2D texture, Rectangle pick_window, Rectangle dest);

#endif
