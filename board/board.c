#include "board.h"
#include "../Utils/random_gen_utils.h"

void init_board(board_state *state)
{
    // Set up initial conditions of board
    // Allocate and create tile array,set resources and ids 
    set_tile_resources_ids(state->tile_arr, resource_count);

    uint_32 randomizer_arr[NUM_HEXS];
    for ( uint_16 i = NUM_HEXS-1; i >= 0; i--) {
        randomizer_arr[i] = i;
    }

    fisher_yates_shuffle(randomizer_arr, NUM_HEXS);

    state->posn_arr = randomizer_arr;


}

void load_board()
{
    char* buffer = 0;
    


    return;
}