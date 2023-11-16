#include "NTDungeon.h"

#include "NTDebug.h"
#include "utils/NTTools.h"


void tileCreate(Vector2 vec, float width, Color color)
{
    Rectangle rec =
        (Rectangle){.width = width, .height = width, .x = vec.x, .y = vec.y};
    DrawRectangleRec(rec, color);
}

void gridSystem(int cols, int lines, bool setted)
{
    if (setted) {
        cols = TILE_COLS;
        lines = TILE_LINES;
    }
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < lines; j++) {
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

/* @brief Cell is a group of tiles.
 * @param width and height is number of tile.
 * @return Vector2 type contains all lines and cols at map.
 * @remark ...
 */
Vector2 NTCreateGridCells(int width, int height)
{
    int cell_width = width + 1;
    int cell_height = height + 1;

    int cell_lines = TILE_LINES / cell_height;
    int cell_cols = TILE_COLS / cell_width;

    // Visual version
#ifdef VISUAL_MODE
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
#endif

    return (Vector2){.x = cell_cols, .y = cell_lines};
}


Vector2 _cellId2Position(NTCell cell)
{
    int cell_width_px = cell.rect.x * TILE_WIDTH;
    int cell_height_px = cell.rect.y * TILE_WIDTH;

    int cell_pos_x =
        TILE_WIDTH + cell.position.x * (cell_width_px + TILE_WIDTH);
    int cell_pos_y =
        TILE_WIDTH + cell.position.y * (cell_height_px + TILE_WIDTH);
    return (Vector2){.x = cell_pos_x, .y = cell_pos_y};
}

Rectangle NTCellToRect(NTCell cell)
{
    int cell_width_px = cell.rect.x * TILE_WIDTH;
    int cell_height_px = cell.rect.y * TILE_WIDTH;

    Vector2 cell_pos = _cellId2Position(cell);

    return (Rectangle){.x = cell_pos.x,
                       .y = cell_pos.y,
                       .width = cell_width_px,
                       .height = cell_height_px};
}

// Connect cell use actual px
void NTConnectCells(NTCell start_cell, NTCell end_cell) {}

void binary_tree_maze(NTUnit** units, int width, int height)
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            NTUnit visited_unit = units[i][j];
            if (j == (height - 1)){  // the last unit
                visited_unit.east = true;
                continue;
            }
            if (i == (width - 1)){
                visited_unit.south = true;
                continue;
            }
            // random select east side or south side
            //               0            1
            int side = NTGetRandomValue(0, 1);
            if (side) {
                visited_unit.south = true;
            } else {
                visited_unit.east = true;
            }
        }
    }
}

void NTPrintMaze(NTUnit** units, int width, int height){
    NTUnit pre_unit;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){

        }
    }
}

void NTPrintDungeon(Rectangle *selected_cells, int cells_num)
{
    /* FloorTile tile[TILE_COLS][TILE_LINES] = {0}; */

    gridSystem(17, 17, false);
    NTUnit units[8][8];
    binary_tree_maze(units, 8, 8);

    /* for (int i = 0; i < cells_num; i++) { */
    /*     int cell_pos_x = selected_cells[i].x; */
    /*     int cell_pos_y = selected_cells[i].y; */
    /*     int cell_width_px = selected_cells[i].width; */
    /*     int cell_height_px = selected_cells[i].height; */
    /*  */
    /*     DrawRectangle(cell_pos_x, cell_pos_y, cell_width_px, cell_height_px,
     * RED); */
    /*     DrawText(TextFormat("%d",i), cell_pos_x, cell_pos_y,
     * GetFontDefault().baseSize * 4, BLUE); */
    /* } */
}
