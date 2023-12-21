#include "../board.h"
#include "tile.h"


void set_tile_resources_ids(tile tile_arr[], int n_resources[])
{
    int n_desert = n_resources[DESERT];
    int n_hills = n_resources[HILLS];
    int n_forests = n_resources[FOREST];
    int n_mountains = n_resources[MOUNTAINS];
    int n_pastures = n_resources[PASTURE];
    int n_fields = n_resources[FIELD];

    for (int i = 0; i < NUM_HEXS; i++) {
        board_tiles[i].id = i;
        if ( i == 0) { 
            board_tiles[i].rtype_ = DESERT; 
        }
        else {
            if (n_mountains > 0) {
                board_tiles[i].rtype_ = MOUNTAINS;
                n_mountains--;
                continue;
            }
            if (n_hills > 0) {
                board_tiles[i].rtype_ = HILLS;
                n_hills--;
                continue;
            }
            if (n_forests > 0) {
                board_tiles[i].rtype_ = FOREST;
                n_forests--;
                continue;
            }
            if (n_fields > 0) {
                board_tiles[i].rtype_ = FIELD;
                n_fields--;
                continue;
            }
            if (n_pastures > 0) {
                board_tiles[i].rtype_ = PASTURE;
                n_pastures--;
                continue;
            }
        }
    }

}