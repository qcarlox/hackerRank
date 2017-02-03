//https://www.hackerrank.com/challenges/between-two-sets
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int cmpfunc (const void * a, const void * b)
{
    if( *(int*)a - *(int*)b < 0 ){
        return -1;
    }
    else if( *(int*)a - *(int*)b > 0 ){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    int n; //size of A
    int m; //size of B
    scanf("%d %d",&n,&m);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(int b_i = 0; b_i < m; b_i++){
       scanf("%d",&b[b_i]);
    }
    qsort(a,n,sizeof(int),cmpfunc);
    qsort(b,m,sizeof(int),cmpfunc);
    
    int count = 0;
    for(int x=a[n-1]; x<=b[0]; x++){
        int flagA = 1;
        for(int i=0; i<n; i++){
            if(x%a[i] != 0){
                flagA = 0;
            }
        }
        int flagB = 1;
        for(int i=0; i<m; i++){
            if(b[i]%x != 0){
                flagB = 0;
            }
        }
        if(flagA + flagB == 2){
            count += 1;
        }
    }
    printf("%d",count);
    return 0;
}
