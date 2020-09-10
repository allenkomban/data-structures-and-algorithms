//
//  asg6q5.c
//  practice
//
//  Created by Allen kombasseril on 6/12/19.
//  Copyright © 2019 Allen kombasseril. All rights reserved.
//

#include <stdio.h>
int main(){
    int i,j,n,k;
    k=0;
    printf("enter how many lines:");
    scanf("%d",&n);
    for (i=0;i<=n;i++){
        for (j=0;j<=n;j++){
            printf("%d ",k);
            k=!k;
        }
        printf("\n");
   
    }
}
    
