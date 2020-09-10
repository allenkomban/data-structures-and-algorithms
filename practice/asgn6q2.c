//
//  asgn6q2.c
//  practice
//
//  Created by Allen kombasseril on 6/12/19.
//  Copyright © 2019 Allen kombasseril. All rights reserved.
//

#include <stdio.h>
int main(){
    int i,j,n;
    printf("enter how many lines:");
    scanf("%d",&n);
    for (i=0;i<=n;i++){
        for (j=0;j<=n;j++){
            printf("*");
        }
        printf("\n");
    }
    for (i=n;i>0;i--){
        for (j=n;j>0;j--){
            printf("*");
        }
        printf("\n");
    }
    
    
    
    
}

