https://www.hackerrank.com/challenges/compare-the-triplets
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    int a[3] = {a0, a1, a2};
    int b[3] = {b0, b1, b2};
    int bobPoint = 0;
    int alicePoint = 0;
    
    for(int i = 0; i<3; i++){
        if(a[i] > b[i]){
            alicePoint += 1;
        }
        if(a[i] < b[i]){
            bobPoint += 1;
        }
    }
    printf("%d %d", alicePoint, bobPoint);
    return 0;
}
