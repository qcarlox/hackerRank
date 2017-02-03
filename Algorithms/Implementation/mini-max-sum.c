//https://www.hackerrank.com/challenges/mini-max-sum
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int cmpfunc (const void * a, const void * b)
{
    if( *(long int*)a - *(long int*)b < 0 ){
        return -1;
    }
    else if( *(long int*)a - *(long int*)b > 0 ){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    long int a; 
    long int b; 
    long int c; 
    long int d;
    long int e;
    scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&d,&e);
    long int array[5] = {a,b,c,d,e};
    qsort(array,5,sizeof(long int),cmpfunc);
    long int minSum = 0;
    long int maxSum = 0;
    for(int i=0; i<5; i++){
        if(i==0){
            minSum += array[i];
        }
        else if(i==4){
            maxSum += array[i];
        }
        else{
            minSum += array[i];
            maxSum += array[i];
        }
    }
    printf("%li %li", minSum, maxSum);
    
    
    return 0;
}
