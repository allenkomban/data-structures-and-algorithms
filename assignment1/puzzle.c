#include<stdio.h>
#include<stdlib.h>
#include"boardADT.h"
#include <stdbool.h>

int main(){


    boardp board_start = create_board();
    boardp board_goal = create_board();

    if(check_if_input_valid(board_start) == false) {
       // printf("Error: Invalid input\n");
        return EXIT_FAILURE;
    }
    if(check_if_input_valid(board_goal) == false) {
       // printf("Error: Invalid input\n");
        return EXIT_FAILURE;
    }


  //  if(orderofnumforboard2(board_goal)==0){
  //      return EXIT_FAILURE;
 //  }

    if (board_are_equal_length(board_start,board_goal)==0){
        return EXIT_FAILURE;
    }

    printf("Start:");
    display_board(board_start);
    printf("\n");
    printf("Goal:");
    display_board(board_goal);
    solvability(board_start, board_goal);
    free_memory(board_start);
    free_memory(board_goal);





    return EXIT_SUCCESS;
    
    
    
}
