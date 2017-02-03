https://www.hackerrank.com/challenges/diagonal-difference
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
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          scanf("%d",&a[a_i][a_j]);
       }
    }
    int primaryDiag = 0;
    int secondaryDiag = 0;
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          if(a_j == a_i){
              primaryDiag += a[a_i][a_j];
          }
          if(a_j+a_i == n-1){
              secondaryDiag += a[a_i][a_j];
          }
       }
    }
    printf("%d", abs(secondaryDiag-primaryDiag));
    return 0;
}
