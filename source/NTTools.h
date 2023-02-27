#ifndef NTTOOLS_H
#define NTTOOLS_H

#include <raylib.h>

// #define MAX_LINE_BUFFER_SIZE 45

float NTGetTextWidthtx(Font used_font, int font_size, char *text);
Vector2 NTGetTextWidth(Font used_font, int font_size, char *text);
// {
//     Vector2 text_rect = {0};
//     int padding = used_font.glyphPadding;
//
//     int size = 0;
//     for (int i = 0; i < MAX_LINE_BUFFER_SIZE; i++) {
//         if ((text[i] != '\0') && (text[i] != '\n'))
//             size++;
//         else
//             break;
//     }
//
//     float scaleFactor = font_size / (float) used_font.baseSize;
//     text_rect.y = (float) used_font.baseSize * scaleFactor;
//     float glyphWidth = 0.0f;
//
//     for (int i = 0, codepointSize = 0; i < size; i += codepointSize) {
//         int codepoint = GetCodepointNext(&text[i], &codepointSize);
//         int codepointIndex = GetGlyphIndex(used_font, codepoint);
//
//         if (used_font.glyphs[codepointIndex].advanceX == 0)
//             glyphWidth =
//                 ((float) used_font.recs[codepointIndex].width * scaleFactor +
//                  padding /* (float) GuiGetStyle(DEFAULT, TEXT_SPACING) */
//                 );
//         else
//             glyphWidth = ((float) used_font.glyphs[codepointIndex].advanceX *
//                               scaleFactor +
//                           padding /* GuiGetStyle(DEFAULT, TEXT_SPACING) */
//             );
//
//         text_rect.x += glyphWidth;
//     }
//     return text_rect;
// }

#endif
