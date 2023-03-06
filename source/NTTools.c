#include "NTTools.h"

#define MAX_LINE_BUFFER_SIZE 45

Vector2 NTGetTextWidthtx(Font used_font, int font_size, char *text)
{
    Vector2 text_rect = {0.0f, 0.0f};
    int padding = used_font.glyphPadding;

    int size = 0;
    for (int i = 0; i < MAX_LINE_BUFFER_SIZE; i++) {
        if ((text[i] != '\0') && (text[i] != '\n'))
            size++;
        else
            break;
    }

    float scaleFactor = font_size / (float) used_font.baseSize;
    text_rect.y = (float) used_font.baseSize * scaleFactor;
    float glyphWidth = 0.0f;

    for (int i = 0, codepointSize = 0; i < size; i += codepointSize) {
        int codepoint = GetCodepointNext(&text[i], &codepointSize);
        int codepointIndex = GetGlyphIndex(used_font, codepoint);

        if (used_font.glyphs[codepointIndex].advanceX == 0)
            glyphWidth = (float) used_font.recs[codepointIndex].width * scaleFactor + padding;
        /* (float) GuiGetStyle(DEFAULT, TEXT_SPACING) */
        else 
            glyphWidth = (float) used_font.glyphs[codepointIndex].advanceX * scaleFactor + padding;


        text_rect.x += glyphWidth;
    }

    return text_rect;
}

Vector2 NTGetTextWidth(Font used_font, int font_size, char *text)
{
    return MeasureTextEx(used_font, text, font_size , 1); // last is padding of
                                                          // text
}


void NTDrawTexture(Texture2D texture, Rectangle pick_window, Rectangle dest)
{
    Vector2 source = (Vector2){0.0, 0.0};
    NPatchInfo ninfo = {pick_window,  // what you want to get
                        0,            // left
                        0,            // top
                        0,            // right
                        0,            // bottom
                        NPATCH_NINE_PATCH};
    DrawTextureNPatch(texture, ninfo, dest, source, 0.0, WHITE);
}
