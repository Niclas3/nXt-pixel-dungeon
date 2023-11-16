#ifndef NTDUNGEON_H
#define NTDUNGEON_H

#include <raylib.h>

#define MAP_WIDTH 960
#define MAP_HEIGHT 720
// #define MAP_WIDTH 2000
// #define MAP_HEIGHT 2000

#define TILE_WIDTH (16)
#define TILE_COLS MAP_WIDTH / TILE_WIDTH
#define TILE_LINES MAP_HEIGHT / TILE_WIDTH

#define MAX_CELL 10
#define MIN_CELL 4

// typedef enum {
//     TILE_SEWER_FLOOR,
// } Tile_Type;
//
// typedef struct{
//     Tile_Type type;
// } FloorTile;

typedef struct {
    Vector2 position;
    Vector2 rect;
} NTCell;

typedef struct{
    bool north;
    bool west;
    bool east;
    bool south;
} NTUnit;

void NTPrintDungeon(Rectangle* rects, int cells_num);
Vector2 NTCreateGridCells(int width, int height);
Rectangle NTCellToRect(NTCell cell);
void NTConnectCells(NTCell start_cell, NTCell end_cell);

#endif
