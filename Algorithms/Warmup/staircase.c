https://www.hackerrank.com/challenges/staircase
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    for(int row = 1; row <= n; row++){
        int spaces = n - row;
        for(int i = 1; i <= spaces; i++){
            printf(" ");
        }
        for(int i = 1; i <= row; i++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

