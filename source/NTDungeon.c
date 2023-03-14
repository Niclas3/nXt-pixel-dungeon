#include "NTDungeon.h"
#include <math.h>
#include <raylib.h>
#include <time.h>

#include "NTDebug.h"
#include "NTTools.h"


#define MAP_WIDTH 960
#define MAP_HEIGHT 720
/* #define MAP_WIDTH (960/5) */
/* #define MAP_HEIGHT (720/5) */

#define TILE_WIDTH (16)
#define TILE_COLS MAP_WIDTH / TILE_WIDTH
#define TILE_LINES MAP_HEIGHT / TILE_WIDTH

#define MAX_CELL 10
#define MIN_CELL 4

void tileCreate(Vector2 vec, float width, Color color)
{
    Rectangle rec =
        (Rectangle){.width = width, .height = width, .x = vec.x, .y = vec.y};
    DrawRectangleRec(rec, color);
}

void gridSystem()
{
    for (int i = 0; i < TILE_COLS; i++) {
        for (int j = 0; j < TILE_LINES; j++) {
            Vector2 vec = (Vector2){.x = i * TILE_WIDTH, .y = j * TILE_WIDTH};
            Color c = BLACK;
            if (i % 2 == 0) {
                if (j % 2 == 0)
                    c = BLACK;
                else
                    c = YELLOW;
            } else {
                if (j % 2 != 0)
                    c = BLACK;
                else
                    c = YELLOW;
            }
            tileCreate(vec, TILE_WIDTH, c);
        }
    }
}

// Cell is a group of tiles
Vector2 CreateCells(int width, int height)
{
    int cell_width = width + 1;
    int cell_height = height + 1;

    int cell_lines = TILE_LINES / cell_height;
    int cell_cols = TILE_COLS / cell_width;

    for (int x = 0; x < TILE_COLS; x++) {
        for (int y = 0; y < TILE_LINES; y++) {
            Vector2 vec = (Vector2){.x = x * TILE_WIDTH, .y = y * TILE_WIDTH};
            Color c = BLUE;
            if ((y % cell_height == 0) || (x % cell_width == 0))
                c = GREEN;
            else
                c = BLUE;
            tileCreate(vec, TILE_WIDTH, c);
        }
    }

    return (Vector2){.x = cell_cols, .y = cell_lines};
}

void SelectCell(Vector2 cell_pos, Vector2 cell_wh)
{
    int cell_width_px = cell_wh.x * TILE_WIDTH;
    int cell_height_px = cell_wh.y * TILE_WIDTH;

    int cell_pos_x = TILE_WIDTH + cell_pos.x * (cell_width_px + TILE_WIDTH);
    int cell_pos_y = TILE_WIDTH + cell_pos.y * (cell_height_px + TILE_WIDTH);

    DrawRectangle(cell_pos_x, cell_pos_y, cell_width_px, cell_height_px, RED);
}

void CreateDungeon()
{
    FloorTile tile[TILE_COLS][TILE_LINES] = {0};
    int cell_width = 4;
    int cell_height = 4;
    Vector2 v_cells = CreateCells(cell_width, cell_height);
    int rand_x;
    int rand_y;

    for (int j = 0; j < 20; j++) {
        rand_x = GetRandomValue(0, (int) v_cells.x - 1);
        rand_y = GetRandomValue(0, (int) v_cells.y - 1);

        SelectCell((Vector2){rand_x, rand_y},
                   (Vector2){cell_width, cell_height});
    }
}
