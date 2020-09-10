#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "boardADT.h"
#define MAX 100000000

bool check_valid(boardp b);
//void input(boardp b);
void solvability(boardp a, boardp b);
void parity(boardp b);
bool size_check(boardp b );
//bool orderofnumforboard2(boardp b);
bool final_check(boardp b);
void num_check(boardp b);
void correction(boardp b);
void display_board(boardp b);
bool cut(boardp b);
bool check_glue(boardp b);

// Takes a boardp as input, returns true or false.
bool check_if_input_valid(boardp b);

// Takes two baords as input, returns true if equal length
bool board_are_equal_length(boardp a, boardp b);

// Takes two baords as input, returns true if equal length


//Prints board
void display_board(boardp b);

void free_memory(boardp b);


struct board{
    
    char *s;
    int *intb;
    int size;
    int parity;
    int validy;
    int sizecheck;
    int bcountcheck;
    int numcheck;
};



// Takes a boardp as input, returns true or false.
bool check_if_input_valid(boardp b){
    
    if(check_valid(b) && check_glue(b) ==1){
       if( cut(b)==0){
           printf("0 is not a valid input");
           return 0;
       }

    }
    else{
        printf("\nERROR: input not valid, only digits , b and spaces allowed");
        return 0;
    }

    
    correction(b);
    if(b->bcountcheck==0){
        printf("ERROR: number of blank tiles is wrong");
        return 0;
    }
    num_check(b);
    if(b->numcheck==0){
        printf("ERROR: the numbers in the input is wrong");
        return 0;
    }
    if(size_check(b)==0){
        printf("the size of the board is invalid");
        return 0;
    }
    if(final_check(b)==0){
        printf("\nerror in the numbers in input");
        return 0;
        }
        
    return true;
}




void free_memory(boardp b){
    free(b->s);
    free(b->intb);
    b->s=NULL;
    b->intb=NULL;
    free(b);
    b=NULL;

}
bool check_valid(boardp b) {
    
    char *position = b->s; //This is a variable which points to the start of the array user_input. Use this to keep track of the current position when looping through
    while(*position != '\n') {
        if (isdigit(*position) || isspace(*position) || *position=='b' )  {

            
            
        } else {
            
            //printf("%c is not valid \n", *position);
            return 0;
            
            
        }
        position++; //increment to the next memory location of the array user_input
    }
    
    return 1;
}

bool check_glue(boardp b){
    int flg=-10,bcount=0;
    char *position=b->s;
    while(*position != '\n') {
        if (isdigit(*position) ) {
            if(flg==2){
                //printf("error it is glued");
                //return false;
                return 0;

                //exit(EXIT_FAILURE);
            }
            flg=1;
        }
        else if(isspace(*position)){
            
            flg=0;
            
        }
        else if(*position=='b'){
            bcount=bcount+1;
            //printf("\nbcount:%d",bcount);//no of  b check
            if (flg==1){
                //printf("error it is glued");
                //return false;
                return 0;

                
            }
            flg=2;
            
            
        }
        position++;
        //increment to the next memory location of the array user_input
    }
    if(bcount==0 || bcount>1){
        b->bcountcheck=0;
        //printf("\nerror in number of b"); // checks for wrong number of b
        
    }
    else{
        b->bcountcheck=1;
    }
    
    
    
    return 1;
   // return true;
}






bool cut(boardp b){ //cutting and presense of zero checkign
    
    
    b->intb = malloc(MAX*sizeof(int));
    if (b->intb == NULL) {
        printf("createQuack: no memory, aborting\n");
        exit(EXIT_FAILURE); // should pass control back to the caller
    }
    char *point;
    int n=0;
    int count=0;
    
    
    point = strtok(b->s," ");
    while(point  ){
        
       // printf("\nelements \t'%s at %p'\n",point,point);
        
        if(strcmp(point,"0")==0){
           // printf(" invalid input 0\n");
            // remember to exit;
            //exit(EXIT_FAILURE);
            return 0;
            
        }
        *((b->intb)+n)=atoi(point);
       // printf("\nelemebt after converting to int %d at %p ",*((b->intb)+n),(b->intb)+n);
        point = strtok(NULL," ");
        n++;
        count++;
        
    }
    
    
    b->size=count;
    return 1;
}



void display_board(boardp b){
    for(int i=0;i<b->size;i++){
        if(*((b->intb)+i)!=0){
        printf(" %d",*((b->intb)+i));}
        else{
            printf(" b");
        }
    }
    
}



void correction(boardp b){
    int z;
    z=0;
    for(int i=0;i<(b->size);i++){
        
        if(*((b->intb)+i)==0){
            z++;}
        
    }
    if(z==2){
        b->size= (b->size)-1;
    }
    else if(z==1){
        b->size= b->size;
        
    }
    else{
        b->bcountcheck=0;
        //printf("error");
        
        //return 0;//remember to exit funtion hhere
        //exit(EXIT_FAILURE);
    }
    
    
}

void num_check(boardp b){
    for(int i=0;i<(b->size);i++){
        if(*((b->intb)+i)<0 || *((b->intb)+i)>=(b->size)){
            //printf(" \nnumbers not valid \n");
            //return false;// remember to exit funtion here.
            //exit(EXIT_FAILURE);
            //return 0;
            b->numcheck=0;

            }
        
    }
   //return 1;
   b->numcheck=1;
    
}

bool final_check(boardp b){
    int flg;
    for(int i=0;i<b->size;i++){
        flg=0;
        for(int q=0;q<b->size;q++){
            if(*((b->intb)+q)==i){
                flg=1;
                }
            }
        if(flg==0){
            
            //return false;//remember to exit here
            return 0;
        }
        }
    
       return 1; 
    }



bool orderofnumforboard2(boardp b){
    int next;
    next=1;
    
    for (int i=0;i<(b->size);i++){
        if(*((b->intb)+i)==0){
        }
        else if(*((b->intb)+i)==next){
            next=next+1;
        }
        else{
            printf("\nError : the ordering of numbers in goal board");
            //return false;
            return 0;
            
        }
        
        
        
    }
    return 1;
    
}
    


bool size_check(boardp b){
    
    int i;
    float j;
    
    if ((b->size)<4 ) {
        
        b->sizecheck=0;
        return 0;

    }
    
    j=sqrt((double)b->size);
    i=j;
    
    if(i==j){
         b->sizecheck=1;}
    else
    {
       // printf("\ninvalid board size ");
        //return false;
        //exit(EXIT_FAILURE);

        b->sizecheck=0;
        return 0;
    }
    return 1;
    
    
}


void parity(boardp b){
    int t=sqrt(b->size);
    int *tiledisorder=malloc((b->size)*sizeof(int));
    if (tiledisorder == NULL) {
        printf("\ncreateQuack: no memory, aborting\n");
        exit(EXIT_FAILURE); // should pass control back to the caller
    }
    int brow;
    int tile_disorder,temp;
    int parity=0;
    
    for(int i=0;i<(b->size);i++){
        tile_disorder=0;
        temp=*((b->intb)+i);
        
        if(*((b->intb)+i)!=0){
        for(int j=i+1;j<(b->size);j++){
            if(temp> *((b->intb)+j) && *((b->intb)+j)!=0){
                
                tile_disorder=tile_disorder+1;
                }
            }
            *(tiledisorder+i)=tile_disorder;
        }
        else{
            *(tiledisorder+i)=tile_disorder;
            brow=(i/t)+1;
        }
    }
    
    for (int h=0;h<b->size;h++){
       // printf("\ntiledisorder:%d", *(tiledisorder+h));
    }
        
         for(int u=0;u<b->size;u++){
             parity=parity + *(tiledisorder+u);
         }
        
        if(t%2==0){
            parity= parity+brow;
        }
        else{
            
        }
   // printf("\nparity:%d",parity);
    
    if(parity%2==0){
        b->parity= 1;}
    else{
        b->parity= 0;}
    free(tiledisorder);
    tiledisorder=NULL;
        
}

bool board_are_equal_length(boardp a, boardp b){
    if(a->size==b->size){
        
        return 1;
    }
    else{
        printf("\nError:boards are not of the same size ");
        return 0;
    }
}

void solvability(boardp a, boardp b){
    parity(a);
    parity(b);
    if ((a->parity)==(b->parity)){
        
        printf("\nsolvable ");}
    else{
        printf("\nunsolvable");
}

}

boardp create_board(void){
   


    boardp m = malloc(sizeof(struct board));
    if(m==NULL){
        printf( "\ncreateQuack: no memory, aborting");
           exit(EXIT_FAILURE);


    }
     m->s = malloc(MAX*(sizeof(char)));
    if (m->s == NULL) {
        printf( "\ncreateQuack: no memory, aborting");
           exit(EXIT_FAILURE); // should pass control back to the caller
    }
    fgets(m->s,MAX,stdin);
    
    
    return m;
    }







