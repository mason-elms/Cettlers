#ifndef TILE_H_
#define TILE_H_

struct tile;
// Catan board is a set of graph nodes... 
// Edge tiles connect to fewer other tiles
typedef enum {
    DESERT,
    HILLS,                          // Brick
    FOREST,                         // Wood
    MOUNTAINS,                      // Ore
    PASTURE,                        // Sheep
    FIELD                           // Wheat
} resource_type;

typedef struct {
    int* id;
    int roll_val;
    resource_type rtype_;
    tile* neighbors;
} tile;

typedef struct {
    tile* tile_1;
    tile* tile_2;
} edge;

typedef struct {
    edge* edge1;
    edge* edge2;
    edge* edge3;
} vertex;

// 2*2 + 2*4 + 6*7 vertices = 54 vertices
// 72 edges
// 19 faces

// 19 in the middle and count outwards

void set_tile_resources_ids(tile tile_arr[], int n_resources[]);

#endif


