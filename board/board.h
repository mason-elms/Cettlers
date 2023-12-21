#ifndef BOARD_H_
#define BOARD_H_

#include "tile/tile.h"
#include "../Utils/types.h"

#define HEX_WIDTH 10                // char width of hexagons
#define HEX_HEIGHT 5                // number of lines of text in hexagon including bases
#define HEX_BASE_SIZE 4             // number of dashes to make hex base
#define NUM_HEXS 19                 // number of hexagons on board space - TODO expansion number
#define PADDING_H 5                 //chars padding on the sides of the board
#define PADDING_V 2                 //lines padding top/bottom

#define HEXS_V 5
#define HEXS_H 3

const uint_16 board_width = HEX_WIDTH * HEXS_H + (HEXS_V - HEXS_H) * HEX_BASE_SIZE + 2 * (PADDING_H) + 2; //Add 2 for the spaces between the board and the padding
const uint_16 board_height = (HEX_HEIGHT - 2) * HEXS_V + HEXS_V+1 + PADDING_V;
const uint_16 buffer_size = (board_width + 2) * board_height - 1; // Include newlines
const extern bool loaded_;
extern char board[board_width*board_height];

const int resource_count[] = {1, 3, 4, 3, 4, 4};

extern tile board_tiles[NUM_HEXS];

typedef struct {
    tile* tile_arr;
    uint_32* posn_arr;
    //  More things in here some time I guess? Card stacks etc
} board_state;



void init_board(board_state *state);

void load_board()

void update_board_state(board_state *last_state);

void render_board(board_state *state);

#endif