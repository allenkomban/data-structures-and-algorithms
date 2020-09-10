//
//  asng8.c
//  practice
//
//  Created by Allen kombasseril on 6/12/19.
//  Copyright © 2019 Allen kombasseril. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(){
    int r1,r2,sum,g,score,c,inc ;
    r1=(rand()%6) +1;
    r2=(rand()%6)+1;
    sum=r1+r2;
    g=1;
    score=0;
    c=0;inc=0;
    
    while(g>0){
        printf("computer rolled two dice...Guess the sum\nEnter any value less than 0 or 0 to terminate.");
                scanf("%d",&g);
        printf("Enter your guess:");
        scanf("%d",&g);
        
        if(sum!=g){
            printf("Darn! bad attempt,-5\nSum was:%d ",sum);
            score=score-5;
            inc=inc+1;
            
        }
        else{printf("bravo!you were correct. +10");
            score=score+10;
            c=c+1;
            
        }
        printf("Total correct:%d",c);
        printf("total incorrect:%d",inc);
        printf("score:%d",score);
        
        
        
    
    
}
    
    printf("thankyou for playing");
    return 0;
    
    
    
    
    
    
}
