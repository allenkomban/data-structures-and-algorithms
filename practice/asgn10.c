//
//  asgn10.c
//  practice
//
//  Created by Allen kombasseril on 6/13/19.
//  Copyright © 2019 Allen kombasseril. All rights reserved.
//

#include <stdio.h>
int main(){
    int a[10]={0};
    int n,i;
    printf("you can enter atmost a 10 digit number\nenter the number of digits you want to enter:")
    scanf("%d",&n);
    
    if(n>10)
        exit(0);
    
    for(i=10-n;i<10;i--){
        printf("\nInput next digit:");
        scanf("%d",&a[i]);
        printf("\n");
        
        
        
    }
    printf("the number that you gave is:");

    for(i=0;i<10;i++){
        if(i!=0){
            printf("%d",a[i]);
        }
    }
    printf("enter a digit >=1 and <=9 to add:");
    
    
           
}
