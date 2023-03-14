#ifndef NTDUNGEON_H
#define NTDUNGEON_H

typedef enum {
    TILE_SEWER_FLOOR,
} Tile_Type;

typedef struct{
    Tile_Type type;
} FloorTile;

void CreateDungeon();


#endif
