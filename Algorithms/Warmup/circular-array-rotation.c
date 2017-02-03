//https://www.hackerrank.com/challenges/circular-array-rotation
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    int q; 
    scanf("%d %d %d",&n,&k,&q);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
        scanf("%d",&a[a_i]);
    }
    int a_rot[n]; 
    
    for(int j=0; j<n; j++){//# of elements{
        int ixDest = (j+k)%n;
        //printf("ixDest: %d\n",ixDest);
        a_rot[ixDest] = a[j];
    }   

    /*
    for(int j=0; j<n; j++){//# of elements{
        printf("%d",a[j]);
    }
    */
    for(int a0 = 0; a0 < q; a0++){
        int m; 
        scanf("%d",&m);
        printf("%d\n",a_rot[m]);
    }
    return 0;
}
