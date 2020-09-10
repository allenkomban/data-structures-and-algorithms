// point.h
#include <math.h>
#include <stdbool.h>

typedef struct board *boardp;
//boardp create_board(void);


// Takes a boardp as input, returns true or false.
bool check_if_input_valid(boardp b);

// Takes two baords as input, returns true if equal length
bool board_are_equal_length(boardp a, boardp b);

// Takes two baords as input, returns true if equal length
void solvability(boardp a, boardp b);

//Prints board
void display_board(boardp b);

void free_memory(boardp b);
//bool orderofnumforboard2(boardp b);

boardp create_board(void);


